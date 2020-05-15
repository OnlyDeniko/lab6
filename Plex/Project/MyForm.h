#pragma once

#include"TPoint.h"
#include"TLine.h"
#include<vector>
#include <msclr\marshal_cppstd.h>
#include"Plex.h"

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	std::vector<TPoint*> Dots;
	std::vector<TLine*> Lines;
	Plex *flex;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  picture;
	private: System::Windows::Forms::DataGridView^  GridDots;




	private: System::Windows::Forms::Label^  LabelMovePoint;
	private: System::Windows::Forms::TextBox^  TextBoxNamePointToMove;
	private: System::Windows::Forms::TextBox^  TextBoxDxPointToMove;
	private: System::Windows::Forms::TextBox^  TextBoxDyPointToMove;



	private: System::Windows::Forms::Label^  LabelNamePointToMove;
	private: System::Windows::Forms::Label^  LabelDyPointToMove;
	private: System::Windows::Forms::Label^  LabelDxPointToMove;
	private: System::Windows::Forms::Button^  ButtonMovePoint;
	private: System::Windows::Forms::Label^  LabelCreateLine;
	private: System::Windows::Forms::Label^  LabelName1CreateLine;
	private: System::Windows::Forms::Label^  LabelName2CreateLine;
	private: System::Windows::Forms::TextBox^  TextBoxCreateLine1;
	private: System::Windows::Forms::TextBox^  TextBoxCreateLine2;
	private: System::Windows::Forms::Button^  ButtonCreateLine;
	private: System::Windows::Forms::DataGridView^  GridLines;
	private: System::Windows::Forms::TextBox^  TextBoxNameDot;
	private: System::Windows::Forms::Label^  LabelCurrentDotName;
	private: System::Windows::Forms::Button^  AddPlexButton;
	private: System::Windows::Forms::Button^  DrawPlexButton;





	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->GridDots = (gcnew System::Windows::Forms::DataGridView());
			this->LabelMovePoint = (gcnew System::Windows::Forms::Label());
			this->TextBoxNamePointToMove = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxDxPointToMove = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxDyPointToMove = (gcnew System::Windows::Forms::TextBox());
			this->LabelNamePointToMove = (gcnew System::Windows::Forms::Label());
			this->LabelDyPointToMove = (gcnew System::Windows::Forms::Label());
			this->LabelDxPointToMove = (gcnew System::Windows::Forms::Label());
			this->ButtonMovePoint = (gcnew System::Windows::Forms::Button());
			this->LabelCreateLine = (gcnew System::Windows::Forms::Label());
			this->LabelName1CreateLine = (gcnew System::Windows::Forms::Label());
			this->LabelName2CreateLine = (gcnew System::Windows::Forms::Label());
			this->TextBoxCreateLine1 = (gcnew System::Windows::Forms::TextBox());
			this->TextBoxCreateLine2 = (gcnew System::Windows::Forms::TextBox());
			this->ButtonCreateLine = (gcnew System::Windows::Forms::Button());
			this->GridLines = (gcnew System::Windows::Forms::DataGridView());
			this->TextBoxNameDot = (gcnew System::Windows::Forms::TextBox());
			this->LabelCurrentDotName = (gcnew System::Windows::Forms::Label());
			this->AddPlexButton = (gcnew System::Windows::Forms::Button());
			this->DrawPlexButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->BeginInit();
			this->SuspendLayout();
			// 
			// picture
			// 
			this->picture->BackColor = System::Drawing::Color::White;
			this->picture->Location = System::Drawing::Point(12, 12);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(1000, 608);
			this->picture->TabIndex = 0;
			this->picture->TabStop = false;
			this->picture->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pict_MouseDown);
			this->picture->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pict_MouseMove);
			// 
			// GridDots
			// 
			this->GridDots->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->GridDots->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->GridDots->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->GridDots->Location = System::Drawing::Point(1018, 12);
			this->GridDots->Name = L"GridDots";
			this->GridDots->RowHeadersVisible = false;
			this->GridDots->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->GridDots->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->GridDots->Size = System::Drawing::Size(162, 266);
			this->GridDots->TabIndex = 1;
			// 
			// LabelMovePoint
			// 
			this->LabelMovePoint->AutoSize = true;
			this->LabelMovePoint->Location = System::Drawing::Point(1304, 12);
			this->LabelMovePoint->Name = L"LabelMovePoint";
			this->LabelMovePoint->Size = System::Drawing::Size(60, 13);
			this->LabelMovePoint->TabIndex = 2;
			this->LabelMovePoint->Text = L"Move point";
			// 
			// TextBoxNamePointToMove
			// 
			this->TextBoxNamePointToMove->Location = System::Drawing::Point(1258, 32);
			this->TextBoxNamePointToMove->Name = L"TextBoxNamePointToMove";
			this->TextBoxNamePointToMove->Size = System::Drawing::Size(52, 20);
			this->TextBoxNamePointToMove->TabIndex = 3;
			// 
			// TextBoxDxPointToMove
			// 
			this->TextBoxDxPointToMove->Location = System::Drawing::Point(1340, 32);
			this->TextBoxDxPointToMove->Name = L"TextBoxDxPointToMove";
			this->TextBoxDxPointToMove->Size = System::Drawing::Size(37, 20);
			this->TextBoxDxPointToMove->TabIndex = 4;
			// 
			// TextBoxDyPointToMove
			// 
			this->TextBoxDyPointToMove->Location = System::Drawing::Point(1407, 32);
			this->TextBoxDyPointToMove->Name = L"TextBoxDyPointToMove";
			this->TextBoxDyPointToMove->Size = System::Drawing::Size(37, 20);
			this->TextBoxDyPointToMove->TabIndex = 5;
			// 
			// LabelNamePointToMove
			// 
			this->LabelNamePointToMove->AutoSize = true;
			this->LabelNamePointToMove->Location = System::Drawing::Point(1217, 35);
			this->LabelNamePointToMove->Name = L"LabelNamePointToMove";
			this->LabelNamePointToMove->Size = System::Drawing::Size(35, 13);
			this->LabelNamePointToMove->TabIndex = 6;
			this->LabelNamePointToMove->Text = L"Name";
			// 
			// LabelDyPointToMove
			// 
			this->LabelDyPointToMove->AutoSize = true;
			this->LabelDyPointToMove->Location = System::Drawing::Point(1383, 35);
			this->LabelDyPointToMove->Name = L"LabelDyPointToMove";
			this->LabelDyPointToMove->Size = System::Drawing::Size(18, 13);
			this->LabelDyPointToMove->TabIndex = 7;
			this->LabelDyPointToMove->Text = L"dy";
			// 
			// LabelDxPointToMove
			// 
			this->LabelDxPointToMove->AutoSize = true;
			this->LabelDxPointToMove->Location = System::Drawing::Point(1316, 35);
			this->LabelDxPointToMove->Name = L"LabelDxPointToMove";
			this->LabelDxPointToMove->Size = System::Drawing::Size(18, 13);
			this->LabelDxPointToMove->TabIndex = 8;
			this->LabelDxPointToMove->Text = L"dx";
			// 
			// ButtonMovePoint
			// 
			this->ButtonMovePoint->Location = System::Drawing::Point(1220, 58);
			this->ButtonMovePoint->Name = L"ButtonMovePoint";
			this->ButtonMovePoint->Size = System::Drawing::Size(224, 30);
			this->ButtonMovePoint->TabIndex = 9;
			this->ButtonMovePoint->Text = L"Move";
			this->ButtonMovePoint->UseVisualStyleBackColor = true;
			this->ButtonMovePoint->Click += gcnew System::EventHandler(this, &MyForm::ButtonMovePoint_Click);
			// 
			// LabelCreateLine
			// 
			this->LabelCreateLine->AutoSize = true;
			this->LabelCreateLine->Location = System::Drawing::Point(1304, 116);
			this->LabelCreateLine->Name = L"LabelCreateLine";
			this->LabelCreateLine->Size = System::Drawing::Size(61, 13);
			this->LabelCreateLine->TabIndex = 10;
			this->LabelCreateLine->Text = L"Create Line";
			// 
			// LabelName1CreateLine
			// 
			this->LabelName1CreateLine->AutoSize = true;
			this->LabelName1CreateLine->Location = System::Drawing::Point(1217, 142);
			this->LabelName1CreateLine->Name = L"LabelName1CreateLine";
			this->LabelName1CreateLine->Size = System::Drawing::Size(44, 13);
			this->LabelName1CreateLine->TabIndex = 11;
			this->LabelName1CreateLine->Text = L"Name 1";
			// 
			// LabelName2CreateLine
			// 
			this->LabelName2CreateLine->AutoSize = true;
			this->LabelName2CreateLine->Location = System::Drawing::Point(1337, 142);
			this->LabelName2CreateLine->Name = L"LabelName2CreateLine";
			this->LabelName2CreateLine->Size = System::Drawing::Size(44, 13);
			this->LabelName2CreateLine->TabIndex = 12;
			this->LabelName2CreateLine->Text = L"Name 2";
			// 
			// TextBoxCreateLine1
			// 
			this->TextBoxCreateLine1->Location = System::Drawing::Point(1267, 139);
			this->TextBoxCreateLine1->Name = L"TextBoxCreateLine1";
			this->TextBoxCreateLine1->Size = System::Drawing::Size(52, 20);
			this->TextBoxCreateLine1->TabIndex = 13;
			// 
			// TextBoxCreateLine2
			// 
			this->TextBoxCreateLine2->Location = System::Drawing::Point(1392, 139);
			this->TextBoxCreateLine2->Name = L"TextBoxCreateLine2";
			this->TextBoxCreateLine2->Size = System::Drawing::Size(52, 20);
			this->TextBoxCreateLine2->TabIndex = 14;
			// 
			// ButtonCreateLine
			// 
			this->ButtonCreateLine->Location = System::Drawing::Point(1220, 165);
			this->ButtonCreateLine->Name = L"ButtonCreateLine";
			this->ButtonCreateLine->Size = System::Drawing::Size(224, 30);
			this->ButtonCreateLine->TabIndex = 15;
			this->ButtonCreateLine->Text = L"Create";
			this->ButtonCreateLine->UseVisualStyleBackColor = true;
			this->ButtonCreateLine->Click += gcnew System::EventHandler(this, &MyForm::ButtonCreateLine_Click);
			// 
			// GridLines
			// 
			this->GridLines->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->GridLines->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->GridLines->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->GridLines->Location = System::Drawing::Point(1018, 284);
			this->GridLines->Name = L"GridLines";
			this->GridLines->RowHeadersVisible = false;
			this->GridLines->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->GridLines->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->GridLines->Size = System::Drawing::Size(252, 266);
			this->GridLines->TabIndex = 16;
			// 
			// TextBoxNameDot
			// 
			this->TextBoxNameDot->Location = System::Drawing::Point(1018, 573);
			this->TextBoxNameDot->Name = L"TextBoxNameDot";
			this->TextBoxNameDot->Size = System::Drawing::Size(161, 20);
			this->TextBoxNameDot->TabIndex = 17;
			// 
			// LabelCurrentDotName
			// 
			this->LabelCurrentDotName->AutoSize = true;
			this->LabelCurrentDotName->Location = System::Drawing::Point(1054, 557);
			this->LabelCurrentDotName->Name = L"LabelCurrentDotName";
			this->LabelCurrentDotName->Size = System::Drawing::Size(92, 13);
			this->LabelCurrentDotName->TabIndex = 18;
			this->LabelCurrentDotName->Text = L"Current Dot Name";
			// 
			// AddPlexButton
			// 
			this->AddPlexButton->Location = System::Drawing::Point(1307, 284);
			this->AddPlexButton->Name = L"AddPlexButton";
			this->AddPlexButton->Size = System::Drawing::Size(99, 30);
			this->AddPlexButton->TabIndex = 19;
			this->AddPlexButton->Text = L"Добавить плекс";
			this->AddPlexButton->UseVisualStyleBackColor = true;
			this->AddPlexButton->Click += gcnew System::EventHandler(this, &MyForm::AddPlexButton_Click);
			// 
			// DrawPlexButton
			// 
			this->DrawPlexButton->Location = System::Drawing::Point(1307, 320);
			this->DrawPlexButton->Name = L"DrawPlexButton";
			this->DrawPlexButton->Size = System::Drawing::Size(137, 30);
			this->DrawPlexButton->TabIndex = 20;
			this->DrawPlexButton->Text = L"Нарисовать по плексу";
			this->DrawPlexButton->UseVisualStyleBackColor = true;
			this->DrawPlexButton->Click += gcnew System::EventHandler(this, &MyForm::DrawPlexButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1456, 632);
			this->Controls->Add(this->DrawPlexButton);
			this->Controls->Add(this->AddPlexButton);
			this->Controls->Add(this->LabelCurrentDotName);
			this->Controls->Add(this->TextBoxNameDot);
			this->Controls->Add(this->GridLines);
			this->Controls->Add(this->ButtonCreateLine);
			this->Controls->Add(this->TextBoxCreateLine2);
			this->Controls->Add(this->TextBoxCreateLine1);
			this->Controls->Add(this->LabelName2CreateLine);
			this->Controls->Add(this->LabelName1CreateLine);
			this->Controls->Add(this->LabelCreateLine);
			this->Controls->Add(this->ButtonMovePoint);
			this->Controls->Add(this->LabelDxPointToMove);
			this->Controls->Add(this->LabelDyPointToMove);
			this->Controls->Add(this->LabelNamePointToMove);
			this->Controls->Add(this->TextBoxDyPointToMove);
			this->Controls->Add(this->TextBoxDxPointToMove);
			this->Controls->Add(this->TextBoxNamePointToMove);
			this->Controls->Add(this->LabelMovePoint);
			this->Controls->Add(this->GridDots);
			this->Controls->Add(this->picture);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Graphics^ g;
		Bitmap^ Image;
		SolidBrush^ Brush;
		int DotName = -1;
		System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			Image = gcnew Bitmap(picture->Width, picture->Height);
			g = Graphics::FromImage(Image);
			picture->Image = Image;
		}

		void PrintDotsDataGrid() {
			GridDots->RowCount = Dots.size();
			GridDots->ColumnCount = 3;
			GridDots->Columns[0]->HeaderCell->Value = "Name";
			GridDots->Columns[1]->HeaderCell->Value = "X";
			GridDots->Columns[2]->HeaderCell->Value = "Y";
			for (int i = 0; i < Dots.size(); i++) {
				GridDots->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(Dots[i]->GetName());
				GridDots->Rows[i]->Cells[1]->Value = System::Convert::ToString(Dots[i]->GetX());
				GridDots->Rows[i]->Cells[2]->Value = System::Convert::ToString(Dots[i]->GetY());
			}
		}

		std::string TranslateTo26(int x) {
			std::string ans;
			while (x) {
				ans += char(x % 26 + 'A');
				x /= 26;
			}
			std::reverse(ans.begin(), ans.end());
			if (ans.size() == 0) {
				ans += 'A';
			}
			return ans;
		}

		std::string GenerateNewName() {
			return TranslateTo26(++DotName);
		}
		System::Void pict_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			Image = gcnew Bitmap(picture->Image);
			int X = e->X;
			int Y = e->Y;
			std::string name = GenerateNewName();
			
			Dots.push_back(new TPoint(X, Y, name));
			//MessageBox::Show(System::Convert::ToString(mas.size()));
			PrintDotsDataGrid();
			DrawDots();
		}
		System::Void pict_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			int X = e->X;
			int Y = e->Y;
			for (int i = 0; i < Dots.size(); i++) {
				if (Dots[i]->IsFigure(X, Y)) {
					TextBoxNameDot->Text = msclr::interop::marshal_as<String^>(Dots[i]->GetName());
					return;
				}
			}
		}
		int FindNameInDots(std::string s) {
			for (int i = 0; i < Dots.size(); i++) {
				if (Dots[i]->GetName() == s) return i;
			}
			return -1;
		}

		void ClearPictureBox() {
			Image = gcnew Bitmap(picture->Width, picture->Height);
			g->Clear(Color::White);
			picture->Image = Image;
			picture->Refresh();
			picture->Invalidate();
		}

		System::Void ButtonMovePoint_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string NamePointToMove = msclr::interop::marshal_as<std::string>(TextBoxNamePointToMove->Text);
			int dx = System::Convert::ToInt32(TextBoxDxPointToMove->Text);
			int dy = System::Convert::ToInt32(TextBoxDyPointToMove->Text);
			int index = FindNameInDots(NamePointToMove);
			if (index == -1) {
				MessageBox::Show("Такого имени точки не существует!");
				return;
			}
			
			if (flex) {
				TPoint* find = flex->SearchPoint(NamePointToMove);

				if (find) {
					find->MovePoint(dx, dy);
				}
				flex->saveFile();
				flex->saveGraph();
			}
			Dots[index]->MovePoint(dx, dy);
			if (Dots.size()) PrintDotsDataGrid();
			if (Lines.size()) PrintLinesDataGrid();
			
			ClearPictureBox();

			DrawLines();
			DrawDots();
			
		}
	
		void DrawDots() {
			for (int i = 0; i < Dots.size(); i++) {
				delete g;
				g = Graphics::FromImage(Image);
				picture->Image = Image;
				Dots[i]->Draw(g);
				picture->Refresh();
				picture->Invalidate();
			}
		}

		void DrawLines() {
			for (int i = 0; i < Lines.size(); i++) {
				delete g;
				g = Graphics::FromImage(Image);
				picture->Image = Image;
				Lines[i]->Draw(g);
				picture->Refresh();
				picture->Invalidate();
			}
		}

		void PrintLinesDataGrid() {
			GridLines->RowCount = Lines.size();
			GridLines->ColumnCount = 5;
			GridLines->Columns[0]->HeaderCell->Value = "Name";
			GridLines->Columns[1]->HeaderCell->Value = "X1";
			GridLines->Columns[2]->HeaderCell->Value = "Y1";
			GridLines->Columns[3]->HeaderCell->Value = "X2";
			GridLines->Columns[4]->HeaderCell->Value = "Y2";
			for (int i = 0; i < Lines.size(); i++) {
				GridLines->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(Lines[i]->GetName());
				GridLines->Rows[i]->Cells[1]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetLeft()))->GetX());
				GridLines->Rows[i]->Cells[2]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetLeft()))->GetY());
				GridLines->Rows[i]->Cells[3]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetRight()))->GetX());
				GridLines->Rows[i]->Cells[4]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetRight()))->GetY());
			}
		}

		System::Void ButtonCreateLine_Click(System::Object^  sender, System::EventArgs^  e) {
			std::string Name1 = msclr::interop::marshal_as<std::string>(TextBoxCreateLine1->Text);
			std::string Name2 = msclr::interop::marshal_as<std::string>(TextBoxCreateLine2->Text);
			int ind1 = FindNameInDots(Name1);
			int ind2 = FindNameInDots(Name2);
			if (ind1 == -1 || ind2 == -1) {
				MessageBox::Show("Такого имени точки не существует!");
				return;
			}
			std::string NameLine = Name1 + ' ' + Name2;
			Lines.push_back(new TLine(Dots[ind1], Dots[ind2]));
			DrawLines();
			PrintLinesDataGrid();
		}
		System::Void AddPlexButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (!Lines.size()) return;
			
			flex = new Plex(Lines[0]);
			for (int i = 1; i < Lines.size(); i++) {
				flex->addLine(Lines[i]);
			}
			flex->saveFile();
			flex->saveGraph();
			PrintLinesDataGrid();
		}
		System::Void DrawPlexButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if (flex->Empty()) return;
			ClearPictureBox();
			delete g;
			g = Graphics::FromImage(Image);
			picture->Image = Image;
			flex->Draw(g);
			picture->Refresh();
			picture->Invalidate();
		}
};
}
