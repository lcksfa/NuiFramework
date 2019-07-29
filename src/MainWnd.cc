#include "stdafx.h"
#include "MainWnd.h"

const std::wstring MainWnd::kClassName = L"MyDearBoyMainWnd";

MainWnd::MainWnd(/* args */) {}

MainWnd::~MainWnd() {}

std::wstring MainWnd::GetSkinFolder() { return L"basic"; }

std::wstring MainWnd::GetSkinFile() { return L"basic.xml"; }

std::wstring MainWnd::GetWindowClassName() const { return kClassName; }

void MainWnd::InitWindow() {}

LRESULT MainWnd::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) {
    PostQuitMessage(0L);
    return __super::OnClose(uMsg, wParam, lParam, bHandled);
}