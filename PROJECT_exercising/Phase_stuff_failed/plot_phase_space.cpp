#include <TMultiGraph.h>
#include <TGraph.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TLegend.h>
#include <TLatex.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void plot_phase_space()
{
    // Create multi-graph
    TMultiGraph *mg = new TMultiGraph();
    mg->SetTitle("Anharmonic Phase Space;x; p");

    // Read data file with error checking
    std::ifstream fin("PHASE_SPACE_stuff/phase_space.dat");
    if (!fin.is_open())
    {
        std::cerr << "ERROR: Cannot open phase_space.dat" << std::endl;
        return;
    }

    std::string line;
    int trajectory = 0;
    TGraph *g = nullptr;
    int colors[3] = {kRed, kBlue, kGreen};

    while (std::getline(fin, line))
    {
        if (line.empty())
        {
            // Finish current graph
            if (g && g->GetN() > 0)
            {
                g->SetLineColor(colors[trajectory]);
                g->SetMarkerStyle(1);
                mg->Add(g);
                trajectory++;
            }
            g = new TGraph();
            continue;
        }

        double x, p;
        std::stringstream ss(line);
        if (ss >> x >> p)
        {
            if (g)
                g->SetPoint(g->GetN(), x, p);
        }
    }
    fin.close();

    // Add last graph
    if (g && g->GetN() > 0)
    {
        g->SetLineColor(colors[trajectory]);
        mg->Add(g);
    }

    // Debug: Check if we have graphs
    if (mg->GetListOfGraphs()->GetSize() == 0)
    {
        std::cerr << "ERROR: No valid trajectories found!" << std::endl;
        return;
    }

    // Create canvas
    TCanvas *phaseCanvas = new TCanvas("phaseCanvas", "Phase Space", 1000, 800);

    // Draw with axis labels
    mg->Draw("APL");
    mg->GetXaxis()->SetRangeUser(-2.5, 2.5);
    mg->GetYaxis()->SetRangeUser(-2.5, 2.5);

    // Add harmonic reference
    TF1 *harmonicUpper = new TF1("harmonicUpper", "sqrt(1-x*x)", -1.5, 1.5);
    TF1 *harmonicLower = new TF1("harmonicLower", "-sqrt(1-x*x)", -1.5, 1.5);
    harmonicUpper->SetLineColor(kBlack);
    harmonicLower->SetLineColor(kBlack);
    harmonicUpper->SetLineStyle(2);
    harmonicLower->SetLineStyle(2);
    harmonicUpper->Draw("SAME");
    harmonicLower->Draw("SAME");

    // Create legend with safe references
    TLegend *phaseLegend = new TLegend(0.7, 0.7, 0.9, 0.9);
    phaseLegend->AddEntry(harmonicUpper, "Harmonic Oscillator", "l");

    // Add trajectories with validation
    TList *graphs = mg->GetListOfGraphs();
    for (int i = 0; i < graphs->GetSize(); ++i)
    {
        TGraph *gr = dynamic_cast<TGraph *>(graphs->At(i));
        if (gr)
        {
            phaseLegend->AddEntry(gr, Form("A=%.1f", 1.0 + i * 0.5), "l");
        }
    }

    phaseLegend->Draw();

    // Add text label
    TLatex *latex = new TLatex();
    latex->SetNDC();
    latex->SetTextSize(0.03);
    latex->DrawLatex(0.15, 0.85, "#lambda = 0.5");

    phaseCanvas->SaveAs("PHASE_SPACE_stuff/phase_space_comparison.png");
}