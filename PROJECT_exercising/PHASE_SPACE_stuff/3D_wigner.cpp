// 3D_wigner_fixed.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <TTree.h>
#include <TH3.h>
#include <TCanvas.h>
#include <TString.h>
#include <TSystem.h>
#include <algorithm> // for min/max elements

void _3D_wigner()
{
    // Open wavefunction file
    std::ifstream infile("OUTPUT/wavefunctions.dat");
    if (!infile.is_open())
    {
        std::cerr << "Error: Could not open wavefunction.dat" << std::endl;
        return;
    }

    // Vectors to store data
    std::vector<Double_t> x_vals, y_vals, z_vals, real_vals, imag_vals;

    // Parse file line by line
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        Double_t x, val1, val2, val3, val4, real, imag;

        // Read all 7 values but only use x and last two as real/imag
        if (iss >> x >> val1 >> val2 >> val3 >> val4 >> real >> imag)
        {
            // Use first value as x, last two as real/imag
            // Set y=0, z=0 since not provided
            x_vals.push_back(x);
            y_vals.push_back(0); // Default y=0
            z_vals.push_back(0); // Default z=0
            real_vals.push_back(real);
            imag_vals.push_back(imag);
        }
    }
    infile.close();

    // Find data ranges (only x has meaningful values)
    Double_t min_x = *std::min_element(x_vals.begin(), x_vals.end());
    Double_t max_x = *std::max_element(x_vals.begin(), x_vals.end());

    // Use fixed ranges for y and z since they're not in data
    Double_t min_y = -1.0, max_y = 1.0;
    Double_t min_z = -1.0, max_z = 1.0;

    // Create 3D histogram
    Int_t bins = 50;
    TH3D *hpsi = new TH3D("hpsi", "Wavefunction Density",
                          bins, min_x, max_x,
                          bins, min_y, max_y,
                          bins, min_z, max_z);

    // Fill histogram
    for (size_t i = 0; i < x_vals.size(); i++)
    {
        Double_t prob = real_vals[i] * real_vals[i] + imag_vals[i] * imag_vals[i];
        hpsi->Fill(x_vals[i], y_vals[i], z_vals[i], prob);
    }

    // Create canvas
    TCanvas *c = new TCanvas("c", "Wigner Function", 1200, 800);
    c->Divide(2, 2);

    // Draw projections
    c->cd(1);
    hpsi->Project3D("xy")->Draw("COLZ");

    c->cd(2);
    hpsi->Project3D("xz")->Draw("COLZ");

    c->cd(3);
    hpsi->Project3D("yz")->Draw("COLZ");

    c->cd(4);
    hpsi->Draw("ISO");

    c->SaveAs("OUTPUT/wigner_3d_projections.png");

    // 3D visualization
    TCanvas *c3d = new TCanvas("c3d", "3D Wigner", 800, 600);
    hpsi->Draw("ISO");
    c3d->SetTheta(25);
    c3d->SetPhi(45);
    c3d->SaveAs("OUTPUT/wigner_3d_iso.png");
}

// Main function for direct execution
int main()
{
    _3D_wigner();
    return 0;
}