/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainTabs.h"
#include "PreenLookAndFeel.h"


//==============================================================================
/**
    This is the top-level window that we'll pop up. Inside it, we'll create and
    show a component from the MainComponent.cpp file (you can open this file using
    the Jucer to edit it).
 */
class HelloWorldWindow  : public DocumentWindow
{
public:
	//==============================================================================
	HelloWorldWindow()
        : DocumentWindow (ProjectInfo::projectName + String(" ") + ProjectInfo::versionString,
		Colours::lightgrey,
		DocumentWindow::allButtons,
		true)
{
	    setTitleBarHeight(30);
	    // Create an instance of our main content component, and add it to our window..
		setContentOwned (new MainTabs(), true);
		// Centre the window on the screen
		centreWithSize (900, 750);
		// And show it!
		setVisible (true);
}

	~HelloWorldWindow()
	{
		// (the content component will be deleted automatically, so no need to do it here)
	}

	//==============================================================================
	void closeButtonPressed()
	{
		// When the user presses the close button, we'll tell the app to quit. This
		// HelloWorldWindow object will be deleted by the JUCEHelloWorldApplication class.
		JUCEApplication::quit();
	}
};



//==============================================================================
class preenControllerApplication  : public JUCEApplication
{
public:
	//==============================================================================
	preenControllerApplication() {}

	const String getApplicationName()       { return ProjectInfo::projectName; }
	const String getApplicationVersion()    { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed()       { return true; }

	//==============================================================================
	void initialise (const String& commandLine)
	{
		myLookAndFeel = new preenfmLookAndFeel();
		LookAndFeel::setDefaultLookAndFeel(myLookAndFeel);
		// Add your application's initialisation code here..
		helloWorldWindow = new HelloWorldWindow();

	}

	void shutdown()
	{
		// Add your application's shutdown code here..
		delete myLookAndFeel;
	}

	//==============================================================================
	void systemRequestedQuit()
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}

	void anotherInstanceStarted (const String& commandLine)
	{
		// When another instance of the app is launched while this one is running,
		// this method is invoked, and the commandLine parameter tells you what
		// the other instance's command-line arguments were.
		quit();
	}

private:
	ScopedPointer<HelloWorldWindow> helloWorldWindow;
	LookAndFeel* myLookAndFeel;
};

//==============================================================================
// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION (preenControllerApplication)
