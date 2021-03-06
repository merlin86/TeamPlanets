// coordinates.hpp - Coordinates class definition
// libTeamPlanets - A library of common data structures for engine and bots
//
// Copyright (c) 2015 Vadim Litvinov <vadim_litvinov@fastmail.com>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the author nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#ifndef _TEAMPLANETS_LIBTEAMPLANETS_COORDINATES_HPP_
#define _TEAMPLANETS_LIBTEAMPLANETS_COORDINATES_HPP_

#include <cmath>

namespace team_planets {
  class Coordinates {
  public:
    Coordinates(float x = 0.0f, float y = 0.0f):
      x_(x), y_(y) {}
    
    // Accessors
    float x() const { return x_; }
    float y() const { return y_; }
    
    // Various game mechanics functions
    float euclidian_distance(const Coordinates& coord) const {
      const float x_diff = x_ - coord.x_;
      const float y_diff = y_ - coord.y_;
      return std::sqrt(x_diff*x_diff + y_diff*y_diff);
    }

  private:
    template<typename charT, typename traits>
    friend std::basic_ostream<charT,traits>& operator<<(std::basic_ostream<charT,traits>& out,
                                                        const Coordinates& coord);
    template<typename charT, typename traits>
    friend std::basic_istream<charT,traits>& operator>>(std::basic_istream<charT,traits>& in, Coordinates& coord);

    float x_, y_;
  };

  // Input/output operators
  template<typename charT, typename traits>
  std::basic_ostream<charT,traits>& operator<<(std::basic_ostream<charT,traits>& out, const Coordinates& coord) {
    out << coord.x_ << ' ' << coord.y_;
    return out;
  }

  template<typename charT, typename traits>
  std::basic_istream<charT,traits>& operator>>(std::basic_istream<charT,traits>& in, Coordinates& coord) {
    in >> coord.x_ >> coord.y_;
    return in;
  }
}

#endif
