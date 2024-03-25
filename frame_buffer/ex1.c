#include <windows.h>
#include <stdint.h>

// 화면 해상도를 정의합니다.
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// RGB를 나타내는 구조체를 정의합니다.
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} RGBColor;

// 프레임버퍼 구조체를 정의합니다.
typedef struct {
    int width;
    int height;
    RGBColor *pixels; // 픽셀 배열
} FrameBuffer;

// 프레임버퍼 생성 함수
FrameBuffer *createFrameBuffer(int width, int height) {
    FrameBuffer *frameBuffer = (FrameBuffer *)malloc(sizeof(FrameBuffer));
    frameBuffer->width = width;
    frameBuffer->height = height;
    frameBuffer->pixels = (RGBColor *)malloc(width * height * sizeof(RGBColor));
    return frameBuffer;
}

// 프레임버퍼 해제 함수
void destroyFrameBuffer(FrameBuffer *frameBuffer) {
    free(frameBuffer->pixels);
    free(frameBuffer);
}

// 빨간색 이미지를 생성하여 프레임버퍼에 씁니다.
void fillRed(FrameBuffer *frameBuffer) {
    int x, y;
    for (y = 0; y < frameBuffer->height; ++y) {
        for (x = 0; x < frameBuffer->width; ++x) {
            RGBColor *pixel = &frameBuffer->pixels[y * frameBuffer->width + x];
            pixel->red = 255; // 빨간색
            pixel->green = 0;
            pixel->blue = 0;
        }
    }
}

// 프레임버퍼를 윈도우 화면에 출력하는 함수
void drawFrameBuffer(FrameBuffer *frameBuffer, HDC hdc) {
    int x, y;
    for (y = 0; y < frameBuffer->height; ++y) {
        for (x = 0; x < frameBuffer->width; ++x) {
            RGBColor *pixel = &frameBuffer->pixels[y * frameBuffer->width + x];
            SetPixel(hdc, x, y, RGB(pixel->red, pixel->green, pixel->blue));
        }
    }
}

// 윈도우 프로시저
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT: {
            HDC hdc;
            PAINTSTRUCT ps;

            hdc = BeginPaint(hwnd, &ps);

            // 프레임버퍼 그리기
            FrameBuffer *frameBuffer = createFrameBuffer(SCREEN_WIDTH, SCREEN_HEIGHT);
            fillRed(frameBuffer);
            drawFrameBuffer(frameBuffer, hdc);
            destroyFrameBuffer(frameBuffer);

            EndPaint(hwnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // 윈도우 클래스 등록
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("FrameBufferWindow");
    RegisterClass(&wc);

    // 윈도우 생성
    HWND hwnd = CreateWindowEx(
        0,
        TEXT("FrameBufferWindow"),
        TEXT("Frame Buffer Example"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    // 윈도우 표시
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 메시지 루프
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
