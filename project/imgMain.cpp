#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int width, height, channels;//가로 세로, 픽셀당 채널?컴포넌트 갯수?,

    // 1. 이미지 파일 로드 (JPEG, PNG, TGA, BMP 등의 이미지 포맷)
    //각 픽셀의 256 컬러 RGB 값들이 저장되는 배열
    // req_desired_channels가 0이면 원본 채널 유지 (RGB는 3, RGBA는 4)
    // 결로중 한국어가 있으면 실패할수 있음...
    unsigned char* imgDa = stbi_load("butterfly_50jpg.jpg", &width, &height, &channels, 0);//""안에 이미지

    cout << "로드됨?" << endl;

    // 2. 벡터 배열화
    //size_t 란게 배열인텍스 표현하기 좋다더라.
    //unsigned char 0 ~ 255 1바이트의 자료형
    size_t total_bytes = static_cast<size_t>(width) * height * channels;
    vector<unsigned char> pixel_array(imgDa, imgDa + total_bytes);

    // 3. imgDa가 할당한 메모리 해제
    stbi_image_free(imgDa);

    // 3차원 벡터,2차원백터(흑백)
    vector<vector<vector<unsigned char>>> img3Da(height, vector<vector<unsigned char>>(width, vector<unsigned char>(channels)));
    vector<vector<unsigned char>> img2Da(height, vector<unsigned char>(width));


    // 3차원 벡터화
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int z = 0; z < channels; ++z) {
                size_t idx = (static_cast<size_t>(y) * width + x) * channels + z;
                img3Da[y][x][z] = imgDa[idx];
            }
        }
    }

    //흑백
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            size_t idx = (static_cast<size_t>(y) * width + x) * channels;
            img2Da[y][x] = (img3Da[y][x][0] + img3Da[y][x][1] + img3Da[y][x][2]) / 3;
        }
    }

    
    //이미지 출력
    cout << "이미지 출력ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" <<endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            size_t idx = (static_cast<size_t>(y) * width + x) * channels;
            cout << (unsigned int)img2Da[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}