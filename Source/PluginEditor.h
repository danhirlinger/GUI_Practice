/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AmpKnob.h"
#include "ChorusKnob.h"
#include "EchoKnob.h"
#include "EQKnob.h"
#include "MenuKnob.h"
#include "MXRKnob.h"
#include "ReverbKnob.h"
#include "TSKnob.h"

//#include "AmpButton.h"
//#include "BBDButton.h"
//#include "..L&F Overwrites/Buttons/CabinetButton.h"


//==============================================================================
/**
*/
class GUI_PracticeAudioProcessorEditor  : public AudioProcessorEditor,
                                          public Slider::Listener,
                                          public Button::Listener

{
public:
    GUI_PracticeAudioProcessorEditor (GUI_PracticeAudioProcessor&);
    ~GUI_PracticeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider * slider) override;
    void buttonClicked(Button * button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    GUI_PracticeAudioProcessor& audioProcessor;
    
    AmpKnob ampKnob;
    ChorusKnob chorusKnob;
    EchoKnob echoKnob;
    EQKnob eqKnob;
    MenuKnob menuKnob;
    MXRKnob mxrKnob;
    ReverbKnob reverbKnob;
    TSKnob tsKnob;
//    AmpButton ampButton;
    
    Slider amp;
    Slider chorus;
    Slider echo;
    Slider eq;
    Slider menu;
    Slider mxr;
    Slider reverb;
    Slider ts;
    
    ToggleButton ampButtonOn;
    ToggleButton ampButtonOff;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI_PracticeAudioProcessorEditor)
};
