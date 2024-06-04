void B3b(){
	TCanvas * c1 = new TCanvas ("c1","",20,20,1000,1000);
	c1->Divide(2,3);

	TString filename = "~/opt/basic/B3/B3b/scoring.root";
	TFile*f = TFile::Open(filename);

	TH1F*h1 = new TH1F("crystal_edep_eventId","",400,0,200);
	TH1F*h2 = new TH1F("crystal_edep_cell","",400,0,32);
	TH1F*h3 = new TH1F("crystal_edep_score","",400,0,0.6);

	TH1F*h4 = new TH1F("eventId","",400,0,200);
	TH1F*h5 = new TH1F("cell","",400,0,200);
	TH1F*h6 = new TH1F("score","",400,0,200);

	
	TTreeReader r1("crystal_edep", f);
	TTreeReaderValue<int> ce_eventId (r1, "crystal_edep_eventId");
	TTreeReaderValue<int> ce_cell (r1, "crystal_edep_cell");
	TTreeReaderValue<double> ce_score (r1, "crystal_edep_score");

	while (r1.Next()){
		h1->Fill(*ce_eventId);
		h2->Fill(*ce_cell);
		h3->Fill(*ce_score);
	}
		
	TTreeReader r2("patient_dose", f);
	TTreeReaderValue<int> pd_eventId (r2, "patient_dose_eventId");
	TTreeReaderValue<int> pd_cell (r2, "patient_dose_cell");
	TTreeReaderValue<double> pd_score (r2, "patient_dose_score");

	while (r2.Next()){
		h4->Fill(*pd_eventId);
		h5->Fill(*pd_cell);
		h6->Fill(*pd_score);
	}

	c1->cd(1);
	h1->GetXaxis()->SetTitle("x-axis");
	h1->GetXaxis()->CenterTitle();
	h1->GetYaxis()->SetTitle("y-axis");
	h1->GetYaxis()->CenterTitle();
	h1->SetTitle("Crystal edep event Id");
	h1->SetLineColor(5);
	h1->Draw();

	c1->cd(2);
	h2->GetXaxis()->SetTitle("x-axis");
	h2->GetXaxis()->CenterTitle();
	h2->GetYaxis()->SetTitle("y-axis");
	h2->GetYaxis()->CenterTitle();
	h2->SetTitle("Crystal edep Cell");
	h2->SetLineColor(7);
	h2->Draw();

	c1->cd(3);
	h3->GetXaxis()->SetTitle("x-axis");
	h3->GetXaxis()->CenterTitle();
	h3->GetYaxis()->SetTitle("y-axis");
	h3->GetYaxis()->CenterTitle();
	h3->SetTitle("Crystal edep Score");
	h3->SetLineColor(6);
	h3->Draw();
	
	c1->cd(4);
	h4->GetXaxis()->SetTitle("x-axis");
	h4->GetXaxis()->CenterTitle();
	h4->GetYaxis()->SetTitle("y-axis");
	h4->GetYaxis()->CenterTitle();
	h4->SetTitle("Patient Dose Event Id");
	h4->SetLineColor(4);
	h4->Draw();

	c1->cd(5);
	h5->GetXaxis()->SetTitle("x-axis");
	h5->GetXaxis()->CenterTitle();
	h5->GetYaxis()->SetTitle("y-axis");
	h5->GetYaxis()->CenterTitle();
	h5->SetTitle("Patient Dose Cell");
	h5->SetLineColor(8);
	h5->Draw();

	c1->cd(6);
	h6->GetXaxis()->SetTitle("x-axis");
	h6->GetXaxis()->CenterTitle();
	h6->GetYaxis()->SetTitle("y-axis");
	h6->GetYaxis()->CenterTitle();
	h6->SetTitle("Patient Dose Score");
	h6->SetLineColor(3);
	h6->Draw();


}
