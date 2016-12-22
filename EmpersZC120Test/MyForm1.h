#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace EmpersZC120Test {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			findPorts();
			loadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	protected:
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Z-Wave COM Port";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"RS-485 COM Port";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(161, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Baud Rate";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(161, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Baud Rate";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(31, 43);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(31, 104);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(92, 21);
			this->comboBox2->TabIndex = 3;
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->comboBox3->Location = System::Drawing::Point(164, 43);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(92, 21);
			this->comboBox3->TabIndex = 5;
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"9600", L"115200" });
			this->comboBox4->Location = System::Drawing::Point(164, 104);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(92, 21);
			this->comboBox4->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 38);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(164, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 38);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(288, 213);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Name = L"MyForm1";
			this->Text = L"ZC120 Configuration";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	// find available serial ports
	private: void findPorts(void) {
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		this->comboBox1->Items->AddRange(objectArray);
		this->comboBox2->Items->AddRange(objectArray);
	}
	private: void loadData(void) {
		try	{
			StreamReader^ din = File::OpenText("zc120save.txt");
			this->comboBox1->Text = din->ReadLine();
			this->comboBox3->Text = din->ReadLine();
			this->comboBox2->Text = din->ReadLine();
			this->comboBox4->Text = din->ReadLine();
		} catch (Exception^) {
		}
	}
	// Save data to file
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ com1String = this->comboBox1->Text;
		String^ com1Baud = this->comboBox3->Text;
		String^ com2String = this->comboBox2->Text;
		String^ com2Baud = this->comboBox4->Text;
		String^ fileName = "zc120save.txt";
		try {
			StreamWriter^ sw = gcnew StreamWriter(fileName);
			sw->WriteLine(com1String);
			sw->WriteLine(com1Baud);
			sw->WriteLine(com2String);
			sw->WriteLine(com2Baud);
			sw->WriteLine(DateTime::Now);
			sw->Close();
		} catch (Exception^) {
		}
		this->Close();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
	};
}
