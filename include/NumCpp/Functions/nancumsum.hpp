/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
/// @version 1.1
///
/// @section License
/// Copyright 2019 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// @section Description
/// Functions for working with NdArrays
///
#pragma once

#include "NumCpp/Core/StlAlgorithms.hpp"
#include "NumCpp/Core/Types.hpp"
#include "NumCpp/Functions/cumsum.hpp"
#include "NumCpp/NdArray.hpp"

#include <cmath>

namespace nc
{
    //============================================================================
    // Method Description:
    ///						Return the cumulative sum of the elements along a given axis ignoring NaNs.
    ///
    ///                     NumPy Reference: https://www.numpy.org/devdocs/reference/generated/numpy.nancumsum.html
    ///
    /// @param				inArray
    /// @param				inAxis (Optional, default NONE)
    /// @return
    ///				NdArray
    ///
    template<typename dtype>
    NdArray<dtype> nancumsum(const NdArray<dtype>& inArray, Axis inAxis = Axis::NONE) noexcept
    {
        NdArray<dtype> arrayCopy(inArray);
        stl_algorithms::for_each(arrayCopy.begin(), arrayCopy.end(),
            [](dtype& value) noexcept -> void
            {
                if (std::isnan(value)) { value = dtype{ 0 }; };
            });

        return cumsum(arrayCopy, inAxis);
    }
}
