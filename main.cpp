#include "main.h";

int main() {
    // 变量
    cv::Mat image = cv::imread("/Users/ashe/CLionProjects/open-cv-exmaple/static/image/yoasobi.png");
    cv::Mat image_gray;
    cv::Mat image_blurred;
    cv::Mat image_threshold1;
    cv::Mat image_threshold1_blurred;
    cv::Mat image_threshold2;
    cv::Mat image_threshold2_not;
    cv::Mat image_opening;
    cv::Mat image_opening_blurred;

    //读取视频
    cv::VideoCapture cap("/Users/ashe/CLionProjects/open-cv-exmaple/static/cxk.mp4");

    // 开运算
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    while (1) {
        cv::Mat frame;
        cap.read(frame);

        // 灰色
        cv::cvtColor(frame, image_gray, cv::COLOR_BGR2GRAY);

        // 高斯模糊
        cv::GaussianBlur(image_gray, image_blurred, cv::Size(5, 5), 0);

        // 二值化
        cv::adaptiveThreshold(image_blurred, image_threshold1, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5,
                              2);

        // 二值化+高斯模糊
        cv::GaussianBlur(image_threshold1, image_threshold1_blurred, cv::Size(5, 5), 0);

        // 再次二值化
        cv::threshold(image_threshold1_blurred, image_threshold2, 200, 255, cv::THRESH_BINARY);

        // 开运算
        cv::bitwise_not(image_threshold2, image_threshold2_not);
        cv::morphologyEx(image_threshold2_not, image_opening, cv::MORPH_OPEN, kernel);

        // 第三次高斯模糊
        cv::GaussianBlur(image_opening, image_opening_blurred, cv::Size(3, 3), 0);

        cv::imshow("111", image_threshold2);
        cv::waitKey(20);

        if (frame.empty()){
            break;
        }
    }

    return 0;
}
