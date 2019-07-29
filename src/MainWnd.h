#pragma once

class MainWnd : public ui::WindowImplBase {
  private:
    /* data */
  public:
    MainWnd(/* args */);
    ~MainWnd();

    virtual std::wstring GetSkinFolder() override;
    virtual std::wstring GetSkinFile() override;
    virtual std::wstring GetWindowClassName() const override;

    virtual void InitWindow() override;

    virtual LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);

    static const std::wstring kClassName;
};
