#include "stdafx.h"
#include "mydearboy.h"
#include "MainWnd.h"
//fixme :here should make a signton class
Logme gg;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    MainThread thread;

    thread.RunOnCurrentThreadWithLoop(nbase::MessageLoop::kUIMessageLoop);

    return 0;
}

void MainThread::Init() {
    nbase::ThreadManager::RegisterThread(kThreadUI);

    std::wstring theme_dir = QPath::GetAppPath();
    gg.get()->info(L"hello world:{},{}",theme_dir,45645);
#ifdef _DEBUG
    // In order to facilitate in vscode find resources under the root directory of the folder
    theme_dir = L"F:\\66-projects\\v3myboy\\";

    // Debug use local folder
    // default resources\\themes\\default
    // default lan resources\\lang\\zh_CN
    ui::GlobalManager::Startup(theme_dir + L"resources\\", ui::CreateControlCallback(), true);
#else
    // Release use zip
    // THEME name IDR_THEME
    ui::GlobalManager::OpenResZip(MAKEINTRESOURCE(IDR_THEME), L"THEME", "");
    // ui::GlobalManager::OpenResZip(L"resources.zip", "");
    ui::GlobalManager::Startup(L"resources\\", ui::CreateControlCallback(), false);
#endif

    MainWnd *window = new MainWnd();
    window->Create(NULL, MainWnd::kClassName.c_str(), WS_OVERLAPPEDWINDOW & ~WS_MAXIMIZEBOX, 0);
    window->CenterWindow();
    window->ShowWindow();
}

void MainThread::Cleanup() {
    ui::GlobalManager::Shutdown();
    SetThreadWasQuitProperly(true);
    nbase::ThreadManager::UnregisterThread();
}
