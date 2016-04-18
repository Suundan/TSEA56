#ifndef PC_UNIT_H
#define PC_UNIT_H

#include <Windows.h>
#include <iostream>
#include <string>

#pragma once

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for PC_Unit
	/// </summary>
	public ref class PC_Unit : public System::Windows::Forms::Form
	{
	public:
		PC_Unit(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PC_Unit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  openCOMBut;
	private: System::Windows::Forms::Button^  findCOMBut;
	private: static System::IO::Ports::SerialPort^  serialPort1;
	private: static System::IO::Ports::SerialPort^  serialPort2;
	private: static System::Windows::Forms::TextBox^  outPutTextBox;

			 //private: static System::IO::Ports::SerialPort^  serialPort1;
			 //private: static System::IO::Ports::SerialPort^  serialPort2;
			 //private: static System::Windows::Forms::TextBox^  outPutTextBox;

	private: System::Windows::Forms::TextBox^  BluetoothRecievedTextBox;
	private: System::Windows::Forms::ComboBox^  COMComboBox;

	private: System::Windows::Forms::Button^  sendButton;
	private: System::Windows::Forms::TextBox^  commandBox;
	private: System::Windows::Forms::Button^  keyboardBut;

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  labelSensorReadings;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  labelLeftUSFront;
	private: System::Windows::Forms::TextBox^  textBoxLeftUSFront;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::Label^  labelLeftUSRear;
	private: System::Windows::Forms::TextBox^  textBoxLeftUSRear;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel6;
	private: System::Windows::Forms::Label^  labelUSAngle;
	private: System::Windows::Forms::TextBox^  textUSAngle;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel8;
	private: System::Windows::Forms::Label^  labelRightUS;
	private: System::Windows::Forms::TextBox^  textBoxRightUS;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel4;
	private: System::Windows::Forms::Label^  labelLaser;
	private: System::Windows::Forms::TextBox^  textLaser;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel5;
	private: System::Windows::Forms::Label^  labelGyro;
	private: System::Windows::Forms::TextBox^  textGyro;

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel7;
	private: System::Windows::Forms::Label^  labelIR;
	private: System::Windows::Forms::TextBox^  textBoxIR;
	private: System::Windows::Forms::Button^  paintRectBut;




	protected:
		bool keyboardEnabled = false;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PC_Unit::typeid));
			this->openCOMBut = (gcnew System::Windows::Forms::Button());
			this->findCOMBut = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->outPutTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BluetoothRecievedTextBox = (gcnew System::Windows::Forms::TextBox());
			this->COMComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->serialPort2 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->commandBox = (gcnew System::Windows::Forms::TextBox());
			this->keyboardBut = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelSensorReadings = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelLeftUSFront = (gcnew System::Windows::Forms::Label());
			this->textBoxLeftUSFront = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelLeftUSRear = (gcnew System::Windows::Forms::Label());
			this->textBoxLeftUSRear = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel6 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelUSAngle = (gcnew System::Windows::Forms::Label());
			this->textUSAngle = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel8 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelRightUS = (gcnew System::Windows::Forms::Label());
			this->textBoxRightUS = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel4 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelLaser = (gcnew System::Windows::Forms::Label());
			this->textLaser = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel5 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelGyro = (gcnew System::Windows::Forms::Label());
			this->textGyro = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel7 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelIR = (gcnew System::Windows::Forms::Label());
			this->textBoxIR = (gcnew System::Windows::Forms::TextBox());
			this->paintRectBut = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->flowLayoutPanel6->SuspendLayout();
			this->flowLayoutPanel8->SuspendLayout();
			this->flowLayoutPanel4->SuspendLayout();
			this->flowLayoutPanel5->SuspendLayout();
			this->flowLayoutPanel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// openCOMBut
			// 
			this->openCOMBut->Location = System::Drawing::Point(325, 312);
			this->openCOMBut->Name = L"openCOMBut";
			this->openCOMBut->Size = System::Drawing::Size(113, 59);
			this->openCOMBut->TabIndex = 0;
			this->openCOMBut->Text = L"Open COM ports";
			this->openCOMBut->UseVisualStyleBackColor = true;
			this->openCOMBut->Click += gcnew System::EventHandler(this, &PC_Unit::openCOMBut_Click);
			// 
			// findCOMBut
			// 
			this->findCOMBut->Location = System::Drawing::Point(444, 312);
			this->findCOMBut->Name = L"findCOMBut";
			this->findCOMBut->Size = System::Drawing::Size(113, 59);
			this->findCOMBut->TabIndex = 1;
			this->findCOMBut->Text = L"Find COM ports";
			this->findCOMBut->UseVisualStyleBackColor = true;
			this->findCOMBut->Click += gcnew System::EventHandler(this, &PC_Unit::findCOMBut_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &PC_Unit::serialPort1_DataReceived);
			// 
			// outPutTextBox
			// 
			this->outPutTextBox->Location = System::Drawing::Point(12, 312);
			this->outPutTextBox->Multiline = true;
			this->outPutTextBox->Name = L"outPutTextBox";
			this->outPutTextBox->ReadOnly = true;
			this->outPutTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outPutTextBox->Size = System::Drawing::Size(307, 303);
			this->outPutTextBox->TabIndex = 2;
			this->outPutTextBox->Text = L"This box will show program output.";
			this->outPutTextBox->UseWaitCursor = true;
			// 
			// BluetoothRecievedTextBox
			// 
			this->BluetoothRecievedTextBox->ForeColor = System::Drawing::Color::Lime;
			this->BluetoothRecievedTextBox->Location = System::Drawing::Point(563, 312);
			this->BluetoothRecievedTextBox->Multiline = true;
			this->BluetoothRecievedTextBox->Name = L"BluetoothRecievedTextBox";
			this->BluetoothRecievedTextBox->ReadOnly = true;
			this->BluetoothRecievedTextBox->Size = System::Drawing::Size(205, 303);
			this->BluetoothRecievedTextBox->TabIndex = 7;
			this->BluetoothRecievedTextBox->Text = L"This box will show data recieved via Bluetooth.";
			// 
			// COMComboBox
			// 
			this->COMComboBox->Enabled = false;
			this->COMComboBox->FormattingEnabled = true;
			this->COMComboBox->Location = System::Drawing::Point(444, 445);
			this->COMComboBox->Name = L"COMComboBox";
			this->COMComboBox->Size = System::Drawing::Size(113, 28);
			this->COMComboBox->TabIndex = 8;
			this->COMComboBox->Tag = L"";
			// 
			// serialPort2
			// 
			this->serialPort2->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &PC_Unit::serialPort2_DataReceived);
			// 
			// sendButton
			// 
			this->sendButton->BackColor = System::Drawing::Color::Red;
			this->sendButton->Enabled = false;
			this->sendButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->sendButton->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sendButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->sendButton->Location = System::Drawing::Point(325, 537);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(232, 78);
			this->sendButton->TabIndex = 9;
			this->sendButton->Text = L"Send";
			this->sendButton->UseVisualStyleBackColor = false;
			this->sendButton->Click += gcnew System::EventHandler(this, &PC_Unit::sendButton_Click);
			// 
			// commandBox
			// 
			this->commandBox->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->commandBox->Enabled = false;
			this->commandBox->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->commandBox->Location = System::Drawing::Point(325, 490);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(232, 30);
			this->commandBox->TabIndex = 10;
			this->commandBox->Text = L"Write command here";
			// 
			// keyboardBut
			// 
			this->keyboardBut->BackColor = System::Drawing::Color::Yellow;
			this->keyboardBut->Enabled = false;
			this->keyboardBut->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keyboardBut->Location = System::Drawing::Point(325, 419);
			this->keyboardBut->Name = L"keyboardBut";
			this->keyboardBut->Size = System::Drawing::Size(113, 59);
			this->keyboardBut->TabIndex = 11;
			this->keyboardBut->Text = L"Enable keyboard";
			this->keyboardBut->UseVisualStyleBackColor = false;
			this->keyboardBut->Click += gcnew System::EventHandler(this, &PC_Unit::keyboardBut_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::LightPink;
			this->flowLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel1->Controls->Add(this->labelSensorReadings);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel2);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel3);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel6);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel8);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel4);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel5);
			this->flowLayoutPanel1->Controls->Add(this->flowLayoutPanel7);
			this->flowLayoutPanel1->Location = System::Drawing::Point(774, 312);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(244, 303);
			this->flowLayoutPanel1->TabIndex = 12;
			// 
			// labelSensorReadings
			// 
			this->labelSensorReadings->AutoSize = true;
			this->labelSensorReadings->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSensorReadings->Location = System::Drawing::Point(3, 0);
			this->labelSensorReadings->Name = L"labelSensorReadings";
			this->labelSensorReadings->Size = System::Drawing::Size(172, 29);
			this->labelSensorReadings->TabIndex = 13;
			this->labelSensorReadings->Text = L"Sensor Readings";
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel2->Controls->Add(this->labelLeftUSFront);
			this->flowLayoutPanel2->Controls->Add(this->textBoxLeftUSFront);
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 32);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel2->TabIndex = 13;
			// 
			// labelLeftUSFront
			// 
			this->labelLeftUSFront->AutoSize = true;
			this->labelLeftUSFront->Location = System::Drawing::Point(3, 0);
			this->labelLeftUSFront->Name = L"labelLeftUSFront";
			this->labelLeftUSFront->Size = System::Drawing::Size(105, 20);
			this->labelLeftUSFront->TabIndex = 0;
			this->labelLeftUSFront->Text = L"Left US front:";
			// 
			// textBoxLeftUSFront
			// 
			this->textBoxLeftUSFront->Location = System::Drawing::Point(3, 23);
			this->textBoxLeftUSFront->Name = L"textBoxLeftUSFront";
			this->textBoxLeftUSFront->ReadOnly = true;
			this->textBoxLeftUSFront->Size = System::Drawing::Size(105, 26);
			this->textBoxLeftUSFront->TabIndex = 1;
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel3->Controls->Add(this->labelLeftUSRear);
			this->flowLayoutPanel3->Controls->Add(this->textBoxLeftUSRear);
			this->flowLayoutPanel3->Location = System::Drawing::Point(124, 32);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel3->TabIndex = 14;
			// 
			// labelLeftUSRear
			// 
			this->labelLeftUSRear->AutoSize = true;
			this->labelLeftUSRear->Location = System::Drawing::Point(3, 0);
			this->labelLeftUSRear->Name = L"labelLeftUSRear";
			this->labelLeftUSRear->Size = System::Drawing::Size(100, 20);
			this->labelLeftUSRear->TabIndex = 0;
			this->labelLeftUSRear->Text = L"Left US rear:";
			// 
			// textBoxLeftUSRear
			// 
			this->textBoxLeftUSRear->Location = System::Drawing::Point(3, 23);
			this->textBoxLeftUSRear->Name = L"textBoxLeftUSRear";
			this->textBoxLeftUSRear->ReadOnly = true;
			this->textBoxLeftUSRear->Size = System::Drawing::Size(105, 26);
			this->textBoxLeftUSRear->TabIndex = 1;
			// 
			// flowLayoutPanel6
			// 
			this->flowLayoutPanel6->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel6->Controls->Add(this->labelUSAngle);
			this->flowLayoutPanel6->Controls->Add(this->textUSAngle);
			this->flowLayoutPanel6->Location = System::Drawing::Point(3, 99);
			this->flowLayoutPanel6->Name = L"flowLayoutPanel6";
			this->flowLayoutPanel6->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel6->TabIndex = 17;
			// 
			// labelUSAngle
			// 
			this->labelUSAngle->AutoSize = true;
			this->labelUSAngle->Location = System::Drawing::Point(3, 0);
			this->labelUSAngle->Name = L"labelUSAngle";
			this->labelUSAngle->Size = System::Drawing::Size(96, 20);
			this->labelUSAngle->TabIndex = 0;
			this->labelUSAngle->Text = L"L. US angle:";
			// 
			// textUSAngle
			// 
			this->textUSAngle->Location = System::Drawing::Point(3, 23);
			this->textUSAngle->Name = L"textUSAngle";
			this->textUSAngle->ReadOnly = true;
			this->textUSAngle->Size = System::Drawing::Size(105, 26);
			this->textUSAngle->TabIndex = 1;
			// 
			// flowLayoutPanel8
			// 
			this->flowLayoutPanel8->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel8->Controls->Add(this->labelRightUS);
			this->flowLayoutPanel8->Controls->Add(this->textBoxRightUS);
			this->flowLayoutPanel8->Location = System::Drawing::Point(124, 99);
			this->flowLayoutPanel8->Name = L"flowLayoutPanel8";
			this->flowLayoutPanel8->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel8->TabIndex = 19;
			// 
			// labelRightUS
			// 
			this->labelRightUS->AutoSize = true;
			this->labelRightUS->Location = System::Drawing::Point(3, 0);
			this->labelRightUS->Name = L"labelRightUS";
			this->labelRightUS->Size = System::Drawing::Size(74, 20);
			this->labelRightUS->TabIndex = 0;
			this->labelRightUS->Text = L"Right US";
			// 
			// textBoxRightUS
			// 
			this->textBoxRightUS->Location = System::Drawing::Point(3, 23);
			this->textBoxRightUS->Name = L"textBoxRightUS";
			this->textBoxRightUS->ReadOnly = true;
			this->textBoxRightUS->Size = System::Drawing::Size(105, 26);
			this->textBoxRightUS->TabIndex = 1;
			// 
			// flowLayoutPanel4
			// 
			this->flowLayoutPanel4->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel4->Controls->Add(this->labelLaser);
			this->flowLayoutPanel4->Controls->Add(this->textLaser);
			this->flowLayoutPanel4->Location = System::Drawing::Point(3, 166);
			this->flowLayoutPanel4->Name = L"flowLayoutPanel4";
			this->flowLayoutPanel4->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel4->TabIndex = 15;
			// 
			// labelLaser
			// 
			this->labelLaser->AutoSize = true;
			this->labelLaser->Location = System::Drawing::Point(3, 0);
			this->labelLaser->Name = L"labelLaser";
			this->labelLaser->Size = System::Drawing::Size(53, 20);
			this->labelLaser->TabIndex = 0;
			this->labelLaser->Text = L"Laser:";
			// 
			// textLaser
			// 
			this->textLaser->Location = System::Drawing::Point(3, 23);
			this->textLaser->Name = L"textLaser";
			this->textLaser->ReadOnly = true;
			this->textLaser->Size = System::Drawing::Size(105, 26);
			this->textLaser->TabIndex = 1;
			// 
			// flowLayoutPanel5
			// 
			this->flowLayoutPanel5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel5->Controls->Add(this->labelGyro);
			this->flowLayoutPanel5->Controls->Add(this->textGyro);
			this->flowLayoutPanel5->Location = System::Drawing::Point(124, 166);
			this->flowLayoutPanel5->Name = L"flowLayoutPanel5";
			this->flowLayoutPanel5->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel5->TabIndex = 16;
			// 
			// labelGyro
			// 
			this->labelGyro->AutoSize = true;
			this->labelGyro->Location = System::Drawing::Point(3, 0);
			this->labelGyro->Name = L"labelGyro";
			this->labelGyro->Size = System::Drawing::Size(47, 20);
			this->labelGyro->TabIndex = 0;
			this->labelGyro->Text = L"Gyro:";
			// 
			// textGyro
			// 
			this->textGyro->Location = System::Drawing::Point(3, 23);
			this->textGyro->Name = L"textGyro";
			this->textGyro->ReadOnly = true;
			this->textGyro->Size = System::Drawing::Size(105, 26);
			this->textGyro->TabIndex = 1;
			// 
			// flowLayoutPanel7
			// 
			this->flowLayoutPanel7->BackColor = System::Drawing::Color::PaleTurquoise;
			this->flowLayoutPanel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel7->Controls->Add(this->labelIR);
			this->flowLayoutPanel7->Controls->Add(this->textBoxIR);
			this->flowLayoutPanel7->Location = System::Drawing::Point(3, 233);
			this->flowLayoutPanel7->Name = L"flowLayoutPanel7";
			this->flowLayoutPanel7->Size = System::Drawing::Size(115, 61);
			this->flowLayoutPanel7->TabIndex = 18;
			// 
			// labelIR
			// 
			this->labelIR->AutoSize = true;
			this->labelIR->Location = System::Drawing::Point(3, 0);
			this->labelIR->Name = L"labelIR";
			this->labelIR->Size = System::Drawing::Size(69, 20);
			this->labelIR->TabIndex = 0;
			this->labelIR->Text = L"Infrared:";
			// 
			// textBoxIR
			// 
			this->textBoxIR->Location = System::Drawing::Point(3, 23);
			this->textBoxIR->Name = L"textBoxIR";
			this->textBoxIR->ReadOnly = true;
			this->textBoxIR->Size = System::Drawing::Size(105, 26);
			this->textBoxIR->TabIndex = 1;
			// 
			// paintRectBut
			// 
			this->paintRectBut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"paintRectBut.BackgroundImage")));
			this->paintRectBut->ForeColor = System::Drawing::Color::Magenta;
			this->paintRectBut->Location = System::Drawing::Point(444, 378);
			this->paintRectBut->Name = L"paintRectBut";
			this->paintRectBut->Size = System::Drawing::Size(113, 61);
			this->paintRectBut->TabIndex = 13;
			this->paintRectBut->Text = L"Paint rectangle";
			this->paintRectBut->UseVisualStyleBackColor = true;
			this->paintRectBut->Click += gcnew System::EventHandler(this, &PC_Unit::paintRectBut_Click);
			// 
			// PC_Unit
			// 
			this->AcceptButton = this->openCOMBut;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(1113, 730);
			this->Controls->Add(this->paintRectBut);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->keyboardBut);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->COMComboBox);
			this->Controls->Add(this->BluetoothRecievedTextBox);
			this->Controls->Add(this->findCOMBut);
			this->Controls->Add(this->openCOMBut);
			this->Controls->Add(this->outPutTextBox);
			this->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"PC_Unit";
			this->Text = L"PC_Unit";
			this->Load += gcnew System::EventHandler(this, &PC_Unit::PC_Unit_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->flowLayoutPanel6->ResumeLayout(false);
			this->flowLayoutPanel6->PerformLayout();
			this->flowLayoutPanel8->ResumeLayout(false);
			this->flowLayoutPanel8->PerformLayout();
			this->flowLayoutPanel4->ResumeLayout(false);
			this->flowLayoutPanel4->PerformLayout();
			this->flowLayoutPanel5->ResumeLayout(false);
			this->flowLayoutPanel5->PerformLayout();
			this->flowLayoutPanel7->ResumeLayout(false);
			this->flowLayoutPanel7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		delegate void writeRecievedDelegateString(String^ s);
		delegate void writeRecievedDelegateInt(int data);

	public: static void send(String ^s)
	{
		PC_Unit::serialPort2->Write(s);
	}

	private: void writeRecieved(String ^s)
	{
		if (this->BluetoothRecievedTextBox->InvokeRequired)
		{
			writeRecievedDelegateString^ d =
				gcnew writeRecievedDelegateString(this, &PC_Unit::writeRecieved);
			this->Invoke(d, gcnew array<Object^> { s });
		}
		else
		{
			// s->ToUInt16();
			// int i = int::Parse(s);
			this->BluetoothRecievedTextBox->Text += (s + "\n");
		}
		// this->BluetoothRecievedTextBox->Text += "-> " + s;
	}
	private: void writeRecieved(int data)
	{
		if (this->BluetoothRecievedTextBox->InvokeRequired)
		{
			writeRecievedDelegateInt^ d =
				gcnew writeRecievedDelegateInt(this, &PC_Unit::writeRecieved);
			this->Invoke(d, gcnew array<Object^> { data });
		}
		else
		{
			this->BluetoothRecievedTextBox->Text += data;
			// s->ToUInt16();
			// int i = int::Parse(s);
			// this->BluetoothRecievedTextBox->Text += (s + "\n");
		}
		// this->BluetoothRecievedTextBox->Text += "-> " + s;
	}


	public: static void writeToUser(String ^s)
	{
		//this->outPutTextBox->ForeColor = COLOR_HIGHLIGHT;
		PC_Unit::outPutTextBox->Text += "\r\n-> ";
		PC_Unit::outPutTextBox->Text += s;
	}
	private: void findPorts(void)
	{
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		this->COMComboBox->Items->AddRange(objectArray);
	}
	private: System::Void PC_Unit_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void openCOMBut_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->outPutTextBox->Text = "Searching for COM ports...";
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		this->COMComboBox->Items->AddRange(objectArray);
		this->outPutTextBox->Text += "\r\nCOM ports added to the cool combo box";
		SerialPort ^tempSP;
		tempSP = serialPort1;
		tempSP->PortName = objectArray[0]->ToString();
		tempSP->BaudRate = 115200;
		tempSP->Open();
		writeToUser(tempSP->PortName + " is opened");
		tempSP = serialPort2;
		tempSP->PortName = objectArray[1]->ToString();
		tempSP->BaudRate = 115200;
		tempSP->Open();
		writeToUser(tempSP->PortName + " is opened");
		this->keyboardBut->Enabled::set(true);
		this->sendButton->Enabled::set(true);
		this->commandBox->Enabled::set(true);
		this->COMComboBox->Enabled::set(true);
		/*
				if (!this->serialPort1->IsOpen)
				{
					tempSP = serialPort1;
				}
				else
				{
					tempSP = serialPort2;
				}
				tempSP->PortName = this->COMComboBox->Text;
				tempSP->BaudRate = 115200;
				tempSP->Open();
				writeToUser(this->COMComboBox->Text + " is opened");*/
				////this->outPutTextBox->Text = "Connecting to COM ports...\n";
				//PortHandling::ConnectToPorts();
				//if (PortHandling::checkPortHandlers()) {
				//	this->outPutTextBox->Text = "Connected to COM ports successfully\n";
				//}
				//else
				//{
				//this->outPutTextBox->Text = "Attempt to connnect to COM ports failed\n";
				//}
	}
	private: System::Void findCOMBut_Click(System::Object^  sender, System::EventArgs^  e) {
		writeToUser("Searching for COM ports...");
		findPorts();
		writeToUser("\r\nCOM ports added to the cool combo box");
	}
	private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^command = this->commandBox->Text;
		if (this->serialPort2->IsOpen)
		{
			send(command);
			writeToUser("\"" + command + "\"" + " sent");
		}
		else
		{
			writeToUser("Serial port aint open bro");
		}
	}
	private: System::Void keyboardBut_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
		/*writeRecieved("I hear smthn!");
		String ^recieved = serialPort1->ReadExisting();
		writeRecieved(recieved);*/
		//this->BluetoothRecievedTextBox->Text += "->"+"Data recieved";
		/*PC_Unit::BluetoothRecievedTextBox->Text += "->" + "Data recieved";*/
	}
	private: System::Void serialPort2_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
		writeRecieved("\r\nDataread:");
		int lowerbyte = serialPort2->ReadByte();	// Read lower byte of uint16
		int dataread = serialPort2->ReadByte();		// Read higher byte of uint16
		dataread = dataread << 8; // Left-shift by 8 bits to make room for lower byte
		dataread += lowerbyte;
		writeRecieved(dataread);

		//dataread = dataread << 8; // Left-shift by 8 bits to make room for lower byte
		//dataread += lowerbyte;
		//dataread += serialPort2->ReadByte();
		/*array<Byte>^ data;
		serialPort2->Read(data, 0, 2);*/

		//int value = atoi(myString.c_str());

		//String ^recieved = serialPort2->ReadExisting();
		//int datas = std::stoi(*recieved,nullptr,10);
		/*writeRecieved("str length:\r\n");
		writeRecieved(recieved->Length + "\r\n");*/
		//writeRecieved("recieved data: " + recieved + "\r\n");
		//recieved->
		//writeRecieved(datas);
		/*PC_Unit::BluetoothRecievedTextBox->Text += "->" + "Data recieved";*/
		//writeToUser("Data recieved!");
	}
	private: System::Void paintRectBut_Click(System::Object^  sender, System::EventArgs^  e) {
		Drawing::Graphics^ graphics;
		graphics = this->CreateGraphics();
		Drawing::Pen^ pen = gcnew Drawing::Pen(Drawing::Color::Magenta, 3.0f);
		Drawing::Rectangle^ rect = gcnew Drawing::Rectangle(12, 12, 222, 222);
		graphics->DrawRectangle(pen, 12, 12, 222, 222);
		Drawing::SolidBrush^ brush = gcnew Drawing::SolidBrush(Drawing::Color::Lime);
		graphics->FillRectangle(brush, *rect);
		delete pen;
		delete brush;
		delete graphics;
	}
	};
}
#endif // !PC_UNIT_H
