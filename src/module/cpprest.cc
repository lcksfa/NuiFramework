#include "cpprest.h"
#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
int usecpptestsdk() {
    auto fileStream = std::make_shared<ostream>();
    pplx::task<void> requestTask =
        fstream::open_ostream(U("restults.html"))
            .then([=](ostream outFile) {
                *fileStream = outFile;
                http_client client(U("https://www.google.com/"));
                uri_builder builder(U("/search"));
                builder.append_query(U("q"), U("cpprestsdk github"));
                return client.request(methods::GET, builder.to_string());
            })
            .then([=](http_response response) {
                printf("Received response status code :%u\n", response.status_code());
                return response.body().read_to_end(fileStream->streambuf());
            })
            .then([=](size_t) { return fileStream->close(); });
    try {
        requestTask.wait();
    } catch (const std::exception &e) {
        printf("Error exception:%s\n", e.what());
    }
    return 0;
}