#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
int main()
{
    const double lambda = 0.2;
    const double x0 = 1.0, p0 = 0.0;
    const double dt = 0.01, tmax = 50.0;

    std::ofstream out("PHASE_SPACE_stuff/phase_space.dat");
    double x = x0, p = p0;

    for (double t = 0; t < tmax; t += dt)
    {
        // Derivatives
        double dxdt = p;
        double dpdt = -x - lambda * x * x * x;

        // Euler-Cromer integration (stable for oscillators)
        p += dpdt * dt;
        x += dxdt * dt;

        out << x << " " << p << "\n";
    }
    cout << "Phase space data saved to 'phase_space.dat'.\n";
    return 0;
}