{
    TFile *f = new TFile("scatter4350_fixed.root"); // Reading file


//Draw the plot of channels vs counts per bin
    TCanvas *ch4350 = new TCanvas("ch4350", "channels 4350", 2000,2000); // Creates canvas for plotting channel data
    ch4350->Divide(2,2); // Creates pads for each channel

    ch4350->cd(1);
    tree->Draw("data[0]>>h1ch4350");
    h1ch4350->SetTitle("30 DEGREES");
    h1ch4350->GetYaxis()->SetTitle("counts per bin");
    h1ch4350->GetXaxis()->SetTitle("Channel number");
    gPad->SetLogy();
    
    //Gaussian fit and Integration at 30 degree
    TF1 *fun_a1= new TF1("fun_a1","gaus",1500,2400);
    h1ch4350->Fit(fun_a1,"R+");
    mean = fun_a1->GetParameter(1);
    sigma = fun_a1->GetParameter(2);
    std::cout <<"At 30 degree, accumulated counts of Alpha(Li,C,O,F) is: " << fun_a1->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_Li1= new TF1("fun_Li1","gaus",1400,1700);
    h1ch4350->Fit(fun_Li1,"R+");
    mean = fun_Li1->GetParameter(1);
    sigma = fun_Li1->GetParameter(2);
    std::cout << "At 30 degree, accumulated counts of Recoiled 7Li is: " << fun_Li1->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";
    

    ch4350->cd(2);
    tree->Draw("data[1]>>h2ch4350"); 
    h2ch4350->SetTitle("60 DEGREES");
    h2ch4350->GetYaxis()->SetTitle("counts per bin");
    h2ch4350->GetXaxis()->SetTitle("Channel number");
    gPad->SetLogy();
    
    //Gaussian fit and Integration at 60 degree
    TF1 *fun_IneLi2= new TF1("fun_IneLi2","gaus",1020,1290);
    h2ch4350->Fit(fun_IneLi2,"R+");
    mean = fun_IneLi2->GetParameter(1);
    sigma = fun_IneLi2->GetParameter(2);
    std::cout << "At 60 degree, accumulated counts of Alpha generated with Inelastic 7Li is: " << fun_IneLi2->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_Li2= new TF1("fun_Li2","gaus",1290,1510);
    h2ch4350->Fit(fun_Li2,"R+");
    mean = fun_Li2->GetParameter(1);
    sigma = fun_Li2->GetParameter(2);
    std::cout << "At 60 degree, accumulated counts of Alpha generated with 7Li is: " << fun_Li2->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_C2= new TF1("fun_C2","gaus",1650,1900);
    h2ch4350->Fit(fun_C2,"R+");
    mean = fun_C2->GetParameter(1);
    sigma = fun_C2->GetParameter(2);
    std::cout << "At 60 degree, accumulated counts of Alpha generated with 12C is: " << fun_C2->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_F2= new TF1("fun_F2","gaus",1900,2110);
    h2ch4350->Fit(fun_F2,"R+");
    mean = fun_F2->GetParameter(1);
    sigma = fun_F2->GetParameter(2);
    std::cout << "At 60 degree, accumulated counts of Alpha generated with 19F is: " << fun_F2->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";


    ch4350->cd(3);
    tree->Draw("data[2]>>h3ch4350");
    h3ch4350->SetTitle("90 DEGREEES");
    h3ch4350->GetYaxis()->SetTitle("counts per bin");
    h3ch4350->GetXaxis()->SetTitle("Channel number");
    gPad->SetLogy();

    //Gaussian fit and Integration at 90 degree
    TF1 *fun_IneLi3= new TF1("fun_IneLi3","gaus",450,690);
    h3ch4350->Fit(fun_IneLi3,"R+");
    mean = fun_IneLi3->GetParameter(1);
    sigma = fun_IneLi3->GetParameter(2);
    std::cout << "At 90 degree, accumulated counts of Alpha generated with Inelistic 7Li is: " << fun_IneLi3->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_Li3= new TF1("fun_Li3","gaus",690,900);
    h3ch4350->Fit(fun_Li3,"R+");
    mean = fun_Li3->GetParameter(1);
    sigma = fun_Li3->GetParameter(2);
    std::cout << "At 90 degree, accumulated counts of Alpha generated with 7Li is: " << fun_Li3->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_C3= new TF1("fun_C3","gaus",1270,1520);
    h3ch4350->Fit(fun_C3,"R+");
    mean = fun_C3->GetParameter(1);
    sigma = fun_C3->GetParameter(2);
    std::cout << "At 90 degree, accumulated counts of Alpha generated with 12C is: " << fun_C3->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_F3= new TF1("fun_F3","gaus",1700,1820);
    h3ch4350->Fit(fun_F3,"R+");
    mean = fun_F3->GetParameter(1);
    sigma = fun_F3->GetParameter(2);
    std::cout << "At 90 degree, accumulated counts of Alpha generated with 19F is: " << fun_F3->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";


    ch4350->cd(4);
    tree->Draw("data[3]>>h4ch4350(200,0,2000)");    //width of range to get the mean value
    h4ch4350->SetTitle("135 DEGREES");
    h4ch4350->GetYaxis()->SetTitle("counts per bin");
    h4ch4350->GetXaxis()->SetTitle("Channel number");
    gPad->SetLogy();
    
    //Gaussian fit and Integration at 135 degree
    TF1 *fun_Li4= new TF1("fun_Li4","gaus",325,365);
    h4ch4350->Fit(fun_Li4,"R+");
    mean = fun_Li4->GetParameter(1);
    sigma = fun_Li4->GetParameter(2);
    //std::cout << round(mean)-3*round(sigma) << "\n" << round(mean)+3*round(sigma) << "\n" << endl;
    std::cout << "At 135 degree, accumulated counts of Alpha generated with 7Li is: " << fun_Li4->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_Li4_BackGround_left= new TF1("fun_Li4_BackGround_left","[0]+[1]*x",300,320);
    fun_Li4_BackGround_left->SetParameters(0,0.001);
    h4ch4350->Fit(fun_Li4_BackGround_left,"R+");
    BackGround_left = fun_Li4_BackGround_left->Integral(300,320);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with 7Li_BackGround_left is: " << fun_Li4_BackGround_left->Integral(300,320) << "\n";

    TF1 *fun_Li4_BackGround_right= new TF1("fun_Li4_BackGround_right","[0]+[1]*x",380,400);
    fun_Li4_BackGround_right->SetParameters(0,0.001);
    h4ch4350->Fit(fun_Li4_BackGround_right,"R+");
    BackGround_right = fun_Li4_BackGround_right->Integral(380,400);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with 7Li_BackGround_right is: " << fun_Li4_BackGround_right->Integral(380,400) << "\n";
    std::cout << "At 135 degree, subtracting the background, the accumulated counts of Alpha generated with 7Li is: " << fun_Li4->Integral(325,365) - (BackGround_left+BackGround_right)/2/20*(360-320) << "\n";


    TF1 *fun_4= new TF1("fun_4","gaus",630,700);
    h4ch4350->Fit(fun_4,"R+");
    mean = fun_4->GetParameter(1);
    sigma = fun_4->GetParameter(2);
    std::cout << "At 135 degree, accumulated counts of Alpha generated at this peak is: " << fun_4->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_BackGround_left= new TF1("fun_BackGround_left","[0]+[1]*x",590,610);
    fun_BackGround_left->SetParameters(0,0.001);
    h4ch4350->Fit(fun_BackGround_left,"R+");
    BackGround_left = fun_BackGround_left->Integral(590,610);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with BackGround_left is: " << fun_BackGround_left->Integral(590,610) << "\n";

    TF1 *fun_BackGround_right= new TF1("fun_BackGround_right","[0]+[1]*x",710,730);
    fun_BackGround_right->SetParameters(0,0.001);
    h4ch4350->Fit(fun_BackGround_right,"R+");
    BackGround_right = fun_BackGround_right->Integral(710,730);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with BackGround_right is: " << fun_BackGround_right->Integral(710,730) << "\n";
    std::cout << "At 135 degree, subtracting the background, the accumulated counts of Alpha generated at this peak is: " << fun_4->Integral(630,700) - (BackGround_left+BackGround_right)/2/20*(700-630) << "\n";


    TF1 *fun_C4= new TF1("fun_C4","gaus",735,815);
    h4ch4350->Fit(fun_C4,"R+");
    mean = fun_C4->GetParameter(1);
    sigma = fun_C4->GetParameter(2);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with 12C is: " << fun_C4->Integral(round(mean)-3*round(sigma), round(mean)+3*round(sigma)) << "\n";

    TF1 *fun_C4_BackGround_left= new TF1("fun_C4_BackGround_left","[0]+[1]*x",710,730);
    fun_C4_BackGround_left->SetParameters(0,0.001);
    h4ch4350->Fit(fun_C4_BackGround_left,"R+");
    BackGround_left = fun_C4_BackGround_left->Integral(710,730);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with BackGround_left is: " << fun_C4_BackGround_left->Integral(700,720) << "\n";

    TF1 *fun_C4_BackGround_right= new TF1("fun_C4_BackGround_right","[0]+[1]*x",840,860);
    fun_C4_BackGround_right->SetParameters(0,0.001);
    h4ch4350->Fit(fun_C4_BackGround_right,"R+");
    BackGround_right = fun_C4_BackGround_right->Integral(840,860);
    std::cout << "At 135 degree, accumulated counts of Alpha generated with BackGround_right is: " << fun_C4_BackGround_right->Integral(840,860) << "\n";
    std::cout << "At 135 degree, subtracting the background, the accumulated counts of Alpha generated at this peak is: " << fun_C4->Integral(735,815) - (BackGround_left+BackGround_right)/2/20*(815-735) << "\n";

}