/*  
 *  Copyright 2012 Anders Wallin (anders.e.e.wallin "at" gmail.com)
 *  
 *  This file is part of libcutsim.
 *
 *  libcutsim is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  libcutsim is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with libcutsim.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "glvertex.hpp"

namespace cutsim {

/// axis-aligned bounding-box, stores max and min x,y,z coordinates
/// in points minpt and maxpt and provides methods for clearing ad setting these
class Bbox {
public:
    /// default ctor;
    Bbox();
    /// create box 
    Bbox(double minx, double maxx, double miny, double maxy, double minz, double maxz);
    virtual ~Bbox() {};
    /// index into maxpt and minpt returning a vector
    /// [minx maxx miny maxy minz maxz]
    double operator[](const unsigned int idx) const;        
    /// return true if Point p is inside this Bbox
    bool isInside(GLVertex& p) const;
    /// return true if *this overlaps Bbox b
    bool overlaps(const Bbox& other) const;
    /// reset the Bbox (sets initialized=false)
    void clear();
    /// Add a Point to the Bbox.
    /// This enlarges the Bbox so that p is contained within it.
    void addPoint(const GLVertex& p);
    /// string output
    friend std::ostream &operator<<(std::ostream& stream, const Bbox b);
//DATA
    /// the maximum point
    GLVertex maxpt; 
    /// the minimum point
    GLVertex minpt; 
private:
    /// false until one Point or one Triangle has been added
    bool initialized;
};

} // end namespace

// end file bbox.h
