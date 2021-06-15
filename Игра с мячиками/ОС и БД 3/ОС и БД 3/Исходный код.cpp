#include <windows.h> //описание основных функций WinAPI
#include "CBall.h"
#include "CBallsArray.h"
#include "CBallSettingsMonitor.h"
#include "CColoredBall.h"
#include "CHLimiter.h"
#include "Trap.h"
HINSTANCE g_hInstance;
int g_nCmdShow;
HWND g_mainWnd;
RECT rect_wndSize;
HDC hDC;
CBallSettingsMonitor monitor;
DWORD prev_frame_time;
CBallsArray balls(50);
PAINTSTRUCT ps;
RECT rect;
bool gravity;
Trap trap(100, 200, 7000, 2000);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void OnIdle()
{
    DWORD cur_time = GetTickCount64();
    DWORD delta_time = cur_time - prev_frame_time;
    balls.Move(delta_time, &trap);
    if (gravity == TRUE)
        balls.SetGravityFactor(delta_time);
    prev_frame_time = cur_time;
    InvalidateRect(g_mainWnd, NULL, TRUE);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        return 0;
    }
    case WM_PAINT:
    {
        HDC hDC;
        PAINTSTRUCT ps;
        hDC = BeginPaint(hWnd, &ps);
        balls.Draw(hDC);
        monitor.Draw(hDC);
        //вывод состояния гравитации:
        gravity == TRUE ? TextOut(hDC, 1, 345, L"Гравитация включена", strlen((char*)L"Гравитация включена"))
            : TextOut(hDC, 1, 345, L"Гравитация выключена", strlen((char*)L"Гравитация выключена"));
        trap.Draw(hDC);
        EndPaint(hWnd, &ps);
        return 0;
    }
    case WM_SIZE:
    {
        rect.top = 0;
        rect.left = 0;
        rect.bottom = HIWORD(lParam);
        rect.right = LOWORD(lParam);
        GetClientRect(g_mainWnd, &rect_wndSize);
        balls.SetBounds(rect_wndSize);
        return 0;
    }
    case WM_LBUTTONUP:
    {
        double xpos = GET_X_LPARAM(lParam);
        double ypos = GET_Y_LPARAM(lParam);
        double v_x, v_y;
        monitor.GetVXVY(v_x, v_y);
        CBall* cball = balls.Add();
        if (cball != NULL)
        {
            hDC = BeginPaint(hWnd, &ps);
            double v_x, v_y;
            monitor.GetVXVY(v_x, v_y);
            cball->SetParams(xpos, ypos, 10, v_x, v_y, rect_wndSize, 2);
            EndPaint(hWnd, &ps);
        }
        return 0;
    }
    case WM_RBUTTONUP:
    {
        double xpos = GET_X_LPARAM(lParam);
        double ypos = GET_Y_LPARAM(lParam);
        CColoredBall* cball = balls.AddColoredBall();
        if (cball != NULL)
        {
            hDC = BeginPaint(hWnd, &ps);
            double v_x, v_y;
            monitor.GetVXVY(v_x, v_y);
            cball->SetParams(xpos, ypos, 20, 50, 50, rect_wndSize, 4);
            cball->SetColor(0, 150, 150);
            EndPaint(hWnd, &ps);
        }
        return 0;
    }
    case WM_KEYDOWN:
    {
        switch (wParam)
        {
        case VK_DOWN:
            monitor.SpeedDown();
            return 0;
        case VK_UP:
            monitor.SpeedUp();
            return 0;
        case VK_LEFT:
            monitor.AngleUp();
            return 0;
        case VK_RIGHT:
            monitor.AngleDown();
            return 0;
        case 0x47:        
            gravity == TRUE ? gravity = FALSE : gravity = TRUE; //переключатель гравитации (Тернарная условная операция)
            return 0;
        
        }
        break;
    }
    default:
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
BOOL InitAppClass()
{
    ATOM class_id;
    WNDCLASS wc;
    memset(&wc, 0, sizeof(wc));
    wc.lpszMenuName = NULL;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WNDPROC)WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = g_hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszClassName = L"LabWork2";
    class_id = RegisterClass(&wc);
    if (class_id != 0)
        return TRUE;
    return FALSE;
}
BOOL InitWindow()
{
    g_mainWnd = CreateWindow(L"LabWork2", L"Лабораторная работа №2",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        400, 400,
        0, 0,
        g_hInstance,
        0);
    if (!g_mainWnd) return FALSE;
    ShowWindow(g_mainWnd, g_nCmdShow);
    UpdateWindow(g_mainWnd);
    return TRUE;
}
WPARAM StartMessageLoop()
{
    MSG msg;
    while (1)
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                break;
            DispatchMessage(&msg);
        }
        else
        {
            Sleep(50);
            OnIdle();//Функция OnIdle будет вызываться тогда,
            //когда сообщений в очереди нет.
        }
    }
    return msg.wParam;
}
int WINAPI WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    CBall* cball;
    /*cball = balls.Add();
    cball->SetParams(200, 25, 25, 50, 50, rect_wndSize, 6);
    cball = balls.Add();
    cball->SetParams(300, 100, 25, -50, -50, rect_wndSize, 6);*/
    g_hInstance = hInstance;
    g_nCmdShow = nCmdShow;
    prev_frame_time = GetTickCount64();
    if (!InitAppClass())
        return 0;
    if (!InitWindow())
        return 0;
    RECT cr;
    GetClientRect(g_mainWnd, &cr);
    balls.SetBounds(cr);
    return StartMessageLoop();
}