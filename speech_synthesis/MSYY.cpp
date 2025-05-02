// cl.exe /nologo /utf-8 /w /EHsc /Ox /DNDEBUG /MD MSYY.cpp  /link  rpcrt4.lib msvcrt.lib shell32.lib user32.lib gdi32.lib

#include <windows.h>
#include <process.h> // 添加头文件以使用 _spawnlp

// 定义按钮的 ID
#define ID_BUTTON_TOOLS 1
#define ID_BUTTON_MOVE 2
#define ID_BUTTON_CLOSE 3

// 窗口过程回调函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND: // 处理命令消息
        switch (LOWORD(wParam)) {
        case ID_BUTTON_TOOLS: {
            // 使用 pythonw.exe 后台运行 my.py 脚本，不弹出命令行窗口
            _spawnlp(_P_NOWAIT, "pythonw.exe", "pythonw.exe", "my.py", NULL);
        } break;

        case ID_BUTTON_MOVE: {
            // 移动窗口到屏幕中央的顶部
            MoveWindow(hwnd, GetSystemMetrics(SM_CXSCREEN) / 2, 0, 90, 30, TRUE);
            break;
        }
        case ID_BUTTON_CLOSE:
            // 发送关闭消息
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            break;
        }
        break;

    case WM_DESTROY: // 窗口销毁时
        PostQuitMessage(0); // 发送退出消息
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam); // 默认处理
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    const char CLASS_NAME[] = "NoTitleWindow"; // 窗口类名

    // 注册窗口类
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc; // 窗口过程
    wc.hInstance = hInstance; // 实例句柄
    wc.lpszClassName = CLASS_NAME; // 窗口类名
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 背景颜色
    wc.style = CS_HREDRAW | CS_VREDRAW; // 窗口样式

    RegisterClass(&wc); // 注册窗口类

    // 计算窗口位置和大小
    int windowWidth = 90;
    int windowHeight = 30;
    int x = (GetSystemMetrics(SM_CXSCREEN) - windowWidth) / 2; // 水平居中
    int y = (GetSystemMetrics(SM_CYSCREEN) - windowHeight) / 2; // 垂直居中

    // 创建窗口
    HWND hwnd = CreateWindowEx(WS_EX_TOPMOST, CLASS_NAME, NULL, WS_POPUP, x, y, windowWidth, windowHeight, NULL, NULL,
                               hInstance, NULL);
    if (hwnd == NULL) {
        return 0; // 创建失败
    }

    // 创建工具按钮
    HWND hButtonTools = CreateWindow("BUTTON", "MSYY", WS_VISIBLE | WS_CHILD | BS_FLAT, 0, 0, 60, 30, hwnd,
                                     (HMENU)ID_BUTTON_TOOLS, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
    
    // 创建移动按钮
    HWND hButtonMove = CreateWindow("BUTTON", "V", WS_VISIBLE | WS_CHILD | BS_FLAT, 60, 15, 30, 15, hwnd,
                                    (HMENU)ID_BUTTON_MOVE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);
    
    // 创建关闭按钮
    HWND hButtonClose = CreateWindow("BUTTON", "X", WS_VISIBLE | WS_CHILD | BS_FLAT, 60, 0, 30, 15, hwnd,
                                     (HMENU)ID_BUTTON_CLOSE, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

    ShowWindow(hwnd, nShowCmd); // 显示窗口
    UpdateWindow(hwnd); // 更新窗口

    // 消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0; // 退出
}