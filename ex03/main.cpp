/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:25:40 by hparveen          #+#    #+#             */
/*   Updated: 2025/11/18 09:09:41 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

static void printTest(const Point &p, bool inside)
{
    std::cout << "Point (" << p.getX() << ", " << p.getY() << ") is "
                << (inside ? "inside" : "outside") << " the triangle." << std::endl;
}

int main(void)
{
    Point A(0, 0);
    Point B(10, 0);
    Point C(5, 8);
    Point F1(1.5f, 1.5f);
    Point F2(5.2f, 2.1f);
    Point F3(3.7f, 6.9f);

    Point P1(5, 3); // Inside the triangle
    Point P2(10, 0); //exactly on vertex B
    Point P3(7, 10); // Outside the triangle
    Point P4(5, 0); //exactly on edge AB
    Point P5(5, 5); // Inside the triangle

    Point P_F1(3.5f, 3.0f); // Inside the triangle
    Point P_F2(5.0f, 5.0f); // Outside the triangle
    Point P_F3(3.0f, 2.2f); // Inside the triangle
    Point P_F4(1.5f, 1.5f); // exactly on edge AF1
    
    printTest(P1, bsp(A, B, C, P1));
    printTest(P2, bsp(A, B, C, P2));
    printTest(P3, bsp(A, B, C, P3));
    printTest(P4, bsp(A, B, C, P4));
    printTest(P5, bsp(A, B, C, P5));

    printTest(P_F1, bsp(F1, F2, F3, P_F1));
    printTest(P_F2, bsp(F1, F2, F3, P_F2));
    printTest(P_F3, bsp(F1, F2, F3, P_F3));
    printTest(P_F4, bsp(F1, F2, F3, P_F4));
    
    return 0;
}
