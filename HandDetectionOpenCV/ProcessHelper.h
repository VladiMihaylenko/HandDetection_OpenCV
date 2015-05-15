//
//  ProcessHelper.h
//  HandDetectionOpenCV
//
//  Created by Vlad Mihaylenko on 24/03/15.
//  Copyright (c) 2015 Vlad Mihaylenko. All rights reserved.
//

#ifndef __HandDetectionOpenCV__ProcessHelper__
#define __HandDetectionOpenCV__ProcessHelper__
#include <opencv2/opencv.hpp>
#include <functional>

namespace hd_cv  {
    
    typedef uint8_t pixelType;
    static const cv::Size defaultSize = cv::Size(640,480);
    class ProcessHelper {
    public:
        
        static void process_mat(const cv::Mat& mat, std::function<void(int, int)>process) {
            for (auto i = 0; i < mat.rows; i++) {
                for (auto j = 0; j < mat.cols; j++) {
                    process(i, j);
                }
            }
        }
        
        static void process_mat_invert(const cv::Mat& mat, std::function<void(int, int)>process) {
            for (auto i = 0; i < mat.cols; i++) {
                for (auto j = 0; j < mat.rows; j++) {
                    process(j, i);
                }
            }
        }
        
    };
    
    template<typename T>
    std::complex<T> real(const std::complex<T> & c) {
        return std::complex<T>(c.real(), 0);
    }
    
    template<typename T>
    std::vector<T> vallaray_to_vector(const std::valarray<std::complex<T>>& v) {
        std::vector<T> result (v.size());
        for (auto& x : v) {
            result.push_back(x.real());
        }
        return result;
    }
    
}

#endif /* defined(__HandDetectionOpenCV__ProcessHelper__) */
