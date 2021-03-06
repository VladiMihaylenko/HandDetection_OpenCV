//
//  FFT.cpp
//  HandDetectionOpenCV
//
//  Created by Vlad Mihaylenko on 01/04/15.
//  Copyright (c) 2015 Vlad Mihaylenko. All rights reserved.
//

#include "FFT.h"

namespace FFT {
    
    void fft(CArray& x)
    {
        const size_t N = x.size();
        if (N <= 1) return;
        
        // divide
        CArray even = x[std::slice(0, N/2, 2)];
        CArray  odd = x[std::slice(1, N/2, 2)];
        
        // conquer
        fft(even);
        fft(odd);
        
        // combine
        for (size_t k = 0; k < N/2; ++k)
        {
            Complex t = std::polar(1.0, -2 * M_PI * k / N) * odd[k];
            x[k    ] = even[k] + t;
            x[k+N/2] = even[k] - t;
        }
    }

    // inverse fft (in-place)
    void ifft(CArray& x)
    {
        // conjugate the complex numbers
        x = x.apply(std::conj);
        
        // forward fft
        fft( x );
        
        // conjugate the complex numbers again
        x = x.apply(std::conj);
        
        // scale the numbers
        x /= x.size();
    }

}