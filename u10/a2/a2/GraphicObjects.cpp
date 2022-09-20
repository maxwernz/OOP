//
//  GraphicObjects.cpp
//  a2
//
//  Created by Maximilian Wernz on 20.09.22.
//

#include "GraphicObjects.h"

bool Square::is_in(int x, int y) const {
    return ((y > m_y) && (y < m_y + m_width) && (x > m_x) && (x < m_x + m_width));
}

bool Circle::is_in(int x, int y) const {
    return sqrt((m_centerX - x) * (m_centerX - x) + (m_centerY - y) * (m_centerY - y)) < m_radius;
}

bool Rectangle::
