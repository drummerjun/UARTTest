#pragma once
#ifndef _PTHREAD_H_
#define _PTHREAD_H_
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#endif
#include <Windows.h>
#include "MyForm1.h"

/*
#include "OZW/src/Options.h"
#include "OZW/src/Manager.h"
#include "OZW/src/Driver.h"
#include "OZW/src/Node.h"
#include "OZW/src/Group.h"
#include "OZW/src/Notification.h"
#include "OZW/src/value_classes/ValueStore.h"
#include "OZW/src/value_classes/Value.h"
#include "OZW/src/value_classes/ValueBool.h"
#include "OZW/src/platform/Log.h"
#include "OZW/src/Defs.h"
*/
namespace EmpersZC120Test {

	//using namespace OpenZWave;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/*
	typedef struct {
		int m_homeId;
		int m_nodeId;
		bool m_polled;
		list<ValueID> m_values;
	} NodeInfo;

	bool temp = false;
	static int				g_homeId = 0;
	static bool				g_initFailed = false;
	static list<NodeInfo*>	g_nodes;
	static pthread_mutex_t	g_criticalSection;
	static pthread_cond_t	initCond = PTHREAD_COND_INITIALIZER;
	static pthread_mutex_t	initMutex = PTHREAD_MUTEX_INITIALIZER;
	*/
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::IO::Ports::SerialPort^  serialPort2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::ComponentModel::IContainer^  components;

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
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->serialPort2 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 500;
			this->serialPort1->WriteTimeout = 500;
			// 
			// serialPort2
			// 
			this->serialPort2->ReadTimeout = 500;
			this->serialPort2->WriteTimeout = 500;
			// 
			// button1
			// 
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button1->Location = System::Drawing::Point(319, 112);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 64);
			this->button1->TabIndex = 2;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(319, 31);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 64);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Configure";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(26, 31);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(271, 145);
			this->textBox1->TabIndex = 22;
			this->textBox1->Text = L"Hello world!";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(26, 200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 26);
			this->label1->TabIndex = 23;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 255);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Empers ZC120 Tester";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ testString = "EmpersZC120Test123";
	String^ message = "";
	String^ com1String = String::Empty;
	String^ com2String = String::Empty;
	int com1Baud = 115200;
	int com2Baud = 9600;
	int i = 0;
	int pass = 0;
	this->label1->Text = String::Empty;
	this->textBox1->Text = String::Empty;
	this->button1->Text = "Testing...";
	this->button1->Enabled = false;
	this->button2->Enabled = false;

	try {
		StreamReader^ din = File::OpenText("zc120save.txt");
		com1String = din->ReadLine();
		com1Baud = Int32::Parse(din->ReadLine());
		com2String = din->ReadLine();
		com2Baud = Int32::Parse(din->ReadLine());
	} catch (Exception^) {
	}

	try {
		this->serialPort1->PortName = com1String;
		this->serialPort1->BaudRate = com1Baud;
		this->serialPort1->Open();
		printToConsole(L"" + DateTime::Now + ":");
		//initZWaveProtocol(com1String, com1Baud);
	} catch (UnauthorizedAccessException^) {
		this->textBox1->Text += L"Opening Z-Wave COM Port ...... UnauthorizedAccessException\r\n";
		terminateTest();
		return;
	} catch (ArgumentOutOfRangeException^) {
		this->textBox1->Text += L"Opening Z-Wave COM Port ...... ArgumentOutOfRangeException\r\n";
		terminateTest();
		return;
	} catch (ArgumentException^) {
		this->textBox1->Text += L"Opening Z-Wave COM Port ...... ArgumentException\r\n";
		terminateTest();
		return;
	} catch (InvalidOperationException^) {
		this->textBox1->Text += L"Opening Z-Wave COM Port ...... InvalidOperationException\r\n";
		terminateTest();
		return;
	} catch (Exception^) {
		this->textBox1->Text += L"Opening Z-Wave COM Port ...... Exception occured\r\n";
		terminateTest();
		return;
	}
	printToConsole(L"Opening Z-Wave COM Port ...... OK!");
	printToConsole(L"" + com1String + "_" + com1Baud);

	try {
		this->serialPort2->PortName = com2String;
		this->serialPort2->BaudRate = com2Baud;
		this->serialPort2->Open();
	} catch (UnauthorizedAccessException^) {
		this->textBox1->Text += L"Opening RS-485 COM Port ...... UnauthorizedAccessException\r\n";
		terminateTest();
		return;
	} catch (ArgumentOutOfRangeException^) {
		this->textBox1->Text += L"Opening RS-485 COM Port ...... ArgumentOutOfRangeException\r\n";
		terminateTest();
		return;
	} catch (ArgumentException^) {
		this->textBox1->Text += L"Opening RS-485 COM Port ...... ArgumentException\r\n";
		terminateTest();
		return;
	} catch (InvalidOperationException^) {
		this->textBox1->Text += L"Opening RS-485 COM Port ...... InvalidOperationException\r\n";
		terminateTest();
		return;
	} catch (Exception^) {
		this->textBox1->Text += L"Opening RS-485 COM Port ...... Exception occured\r\n";
		terminateTest();
		return;
	}
	printToConsole(L"Opening RS-485 COM Port ...... OK!");
	printToConsole(L"" + com2String + "_" + com2Baud);

	for (i = 0; i < 10; i++) {
		this->serialPort1->WriteLine(testString);
		Sleep(1000);
		try {
			message = this->serialPort2->ReadLine();
			if (String::Compare(message, testString) == 0) {
				pass++;
				printToConsole(L"Verifying data ...... OK!");
			} else {
				printToConsole(L"Verifying data ...... FAIL");
			}
		} catch (TimeoutException^) {
			printToConsole(L"Verifying data ...... TimeoutException");
		}
	}
	Sleep(1000);
	this->button1->Enabled = true;
	this->button2->Enabled = true;
	this->button1->Text = "START";
	if (pass > 7) {
		this->label1->ForeColor = Color::DarkGreen;
		this->label1->Text = "PASS!";
	} else {
		this->label1->ForeColor = Color::Red;
		this->label1->Text = "FAIL...";
	}
	this->serialPort1->Close();
	this->serialPort2->Close();
	printToConsole(L"Closing COM Ports ...... OK!");
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm1^ f1 = gcnew MyForm1();
	f1->ShowDialog();
}
private:
void terminateTest(void) {
	this->textBox1->Text += L"Process terminated! Please check configurations";
	this->button1->Enabled = true;
	this->button2->Enabled = true;
	this->button1->Text = "START";
	this->label1->ForeColor = Color::Red;
	this->label1->Text = "FAIL...";
}
void printToConsole(String^ str) {
	this->textBox1->Text += str + "\r\n";
	this->textBox1->SelectionStart = this->textBox1->TextLength;
	this->textBox1->ScrollToCaret();
}
/*
NodeInfo* GetNodeInfo(Notification const* _notification) {
//-----------------------------------------------------------------------------
// <GetNodeInfo>
// Return the NodeInfo object associated with this notification
//-----------------------------------------------------------------------------
	uint32 const homeId = _notification->GetHomeId();
	uint8 const nodeId = _notification->GetNodeId();
	for (list<NodeInfo*>::iterator it = g_nodes.begin(); it != g_nodes.end(); ++it) {
		NodeInfo* nodeInfo = *it;
		if ((nodeInfo->m_homeId == homeId) && (nodeInfo->m_nodeId == nodeId)){
			return nodeInfo;
		}
	}
	return NULL;
}
void OnNotification(Notification const* _notification, void* _context) {
//-----------------------------------------------------------------------------
// <OnNotification>
// Callback that is triggered when a value, group or node changes
//-----------------------------------------------------------------------------
	// Must do this inside a critical section to avoid conflicts with the main thread
	pthread_mutex_lock(&g_criticalSection);
	switch (_notification->GetType()) {
	case Notification::Type_ValueAdded:
	{
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			// Add the new value to our list
			nodeInfo->m_values.push_back(_notification->GetValueID());
		}
		break;
	}

	case Notification::Type_ValueRemoved:
	{
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			// Remove the value from out list
			for (list<ValueID>::iterator it = nodeInfo->m_values.begin(); it != nodeInfo->m_values.end(); ++it){
				if ((*it) == _notification->GetValueID()){
					nodeInfo->m_values.erase(it);
					break;
				}
			}
		}
		break;
	}

	case Notification::Type_ValueChanged:
	{
		// One of the node values has changed
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			nodeInfo = nodeInfo;		// placeholder for real action
		}
		break;
	}

	case Notification::Type_Group:
	{
		// One of the node's association groups has changed
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			nodeInfo = nodeInfo;		// placeholder for real action
		}
		break;
	}

	case Notification::Type_NodeAdded:
	{
		// Add the new node to our list
		NodeInfo* nodeInfo = new NodeInfo();
		nodeInfo->m_homeId = _notification->GetHomeId();
		nodeInfo->m_nodeId = _notification->GetNodeId();
		nodeInfo->m_polled = false;
		g_nodes.push_back(nodeInfo);
		if (temp == true) {
			Manager::Get()->CancelControllerCommand(_notification->GetHomeId());
		}
		break;
	}

	case Notification::Type_NodeRemoved:
	{
		// Remove the node from our list
		uint32 const homeId = _notification->GetHomeId();
		uint8 const nodeId = _notification->GetNodeId();
		for (list<NodeInfo*>::iterator it = g_nodes.begin(); it != g_nodes.end(); ++it)	{
			NodeInfo* nodeInfo = *it;
			if ((nodeInfo->m_homeId == homeId) && (nodeInfo->m_nodeId == nodeId)){
				g_nodes.erase(it);
				delete nodeInfo;
				break;
			}
		}
		break;
	}

	case Notification::Type_NodeEvent:
	{
		// We have received an event from the node, caused by a
		// basic_set or hail message.
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			nodeInfo = nodeInfo;		// placeholder for real action
		}
		break;
	}

	case Notification::Type_PollingDisabled:
	{
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			nodeInfo->m_polled = false;
		}
		break;
	}

	case Notification::Type_PollingEnabled:
	{
		if (NodeInfo* nodeInfo = GetNodeInfo(_notification)){
			nodeInfo->m_polled = true;
		}
		break;
	}

	case Notification::Type_DriverReady:
	{
		g_homeId = _notification->GetHomeId();
		break;
	}

	case Notification::Type_DriverFailed:
	{
		g_initFailed = true;
		pthread_cond_broadcast(&initCond);
		break;
	}

	case Notification::Type_AwakeNodesQueried:
	case Notification::Type_AllNodesQueried:
	case Notification::Type_AllNodesQueriedSomeDead:
	{
		pthread_cond_broadcast(&initCond);
		break;
	}

	case Notification::Type_DriverReset:
	case Notification::Type_Notification:
	case Notification::Type_NodeNaming:
	case Notification::Type_NodeProtocolInfo:
	case Notification::Type_NodeQueriesComplete:
	default:{}
	}

	pthread_mutex_unlock(&g_criticalSection);
}
void initZWaveProtocol(String^ comPort, int baudRate) {
	pthread_mutexattr_t mutexattr;

	pthread_mutexattr_init(&mutexattr);
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&g_criticalSection, &mutexattr);
	pthread_mutexattr_destroy(&mutexattr);
	pthread_mutex_lock(&initMutex);

	// Create the OpenZWave Manager.
	// The first argument is the path to the config files (where the manufacturer_specific.xml file is located
	// The second argument is the path for saved Z-Wave network state and the log file.  If you leave it NULL 
	// the log file will appear in the program's working directory.
	Options::Create("../../../config/", "", "");
	Options::Get()->AddOptionInt("SaveLogLevel", LogLevel_Detail);
	Options::Get()->AddOptionInt("QueueLogLevel", LogLevel_Debug);
	Options::Get()->AddOptionInt("DumpTrigger", LogLevel_Error);
	Options::Get()->AddOptionInt("PollInterval", 500);
	Options::Get()->AddOptionBool("IntervalBetweenPolls", true);
	Options::Get()->AddOptionBool("ValidateValueChanges", true);
	Options::Get()->Lock();
	Manager::Create();

	// Add a callback handler to the manager.  The second argument is a context that
	// is passed to the OnNotification method.  If the OnNotification is a method of
	// a class, the context would usually be a pointer to that class object, to
	// avoid the need for the notification handler to be a static.
	Manager::Get()->AddWatcher(this->OnNotification, NULL);

	this->serialPort1->PortName = comPort;
	this->serialPort1->BaudRate = baudRate;
	this->serialPort1->Open();

	char c_port[20] = { 0 };
	if (this->serialPort1->PortName->Length < sizeof(c_port)) {
		sprintf(c_port, "%s", this->serialPort1->PortName);
	}
	string port(c_port);

	// Add a Z-Wave Driver
	// Modify this line to set the correct serial port for your PC interface.
	if (String::Compare(this->serialPort1->PortName, "usb") == 0){
		Manager::Get()->AddDriver("HID Controller", Driver::ControllerInterface_Hid);
	} else {
		Manager::Get()->AddDriver(port);
	}

	// Now we just wait for either the AwakeNodesQueried or AllNodesQueried notification,
	// then write out the config file.
	// In a normal app, we would be handling notifications and building a UI for the user.
	pthread_cond_wait(&initCond, &initMutex);

	// Since the configuration file contains command class information that is only 
	// known after the nodes on the network are queried, wait until all of the nodes 
	// on the network have been queried (at least the "listening" ones) before
	// writing the configuration file.  (Maybe write again after sleeping nodes have
	// been queried as well.)
	if (!g_initFailed){
		// The section below demonstrates setting up polling for a variable.  In this simple
		// example, it has been hardwired to poll COMMAND_CLASS_BASIC on the each node that 
		// supports this setting.
		pthread_mutex_lock(&g_criticalSection);
		for (list<NodeInfo*>::iterator it = g_nodes.begin(); it != g_nodes.end(); ++it)	{
			NodeInfo* nodeInfo = *it;

			// skip the controller (most likely node 1)
			if (nodeInfo->m_nodeId == 1) continue;
			for (list<ValueID>::iterator it2 = nodeInfo->m_values.begin(); it2 != nodeInfo->m_values.end(); ++it2){
				ValueID v = *it2;
				if (v.GetCommandClassId() == COMMAND_CLASS_BASIC){
					//Manager::Get()->EnablePoll( v, 2 );		// enables polling with "intensity" of 2, though this is irrelevant with only one value polled
					break;
				}
			}
		}
		pthread_mutex_unlock(&g_criticalSection);

		// If we want to access our NodeInfo list, that has been built from all the
		// notification callbacks we received from the library, we have to do so
		// from inside a Critical Section.  This is because the callbacks occur on other 
		// threads, and we cannot risk the list being changed while we are using it.  
		// We must hold the critical section for as short a time as possible, to avoid
		// stalling the OpenZWave drivers.
		// At this point, the program just waits for 3 minutes (to demonstrate polling),
		// then exits
		for (int i = 0; i < 60 * 3; i++){
			pthread_mutex_lock(&g_criticalSection);
			// but NodeInfo list and similar data should be inside critical section
			pthread_mutex_unlock(&g_criticalSection);
			Sleep(1);
		}

		Driver::DriverData data;
		Manager::Get()->GetDriverStatistics(g_homeId, &data);
	}

	// program exit (clean up)
	if (String::Compare(this->serialPort1->PortName, "usb") == 0){
		Manager::Get()->RemoveDriver("HID Controller");
	}else{
		Manager::Get()->RemoveDriver(port);
	}
	//Manager::Get()->RemoveWatcher(this->OnNotification, NULL);
	Manager::Destroy();
	Options::Destroy();
	pthread_mutex_destroy(&g_criticalSection);
}
*/
};
}
