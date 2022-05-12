/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "AmpKnob.h"
#include "MenuKnob.h"

//==============================================================================
/**
*/
class GUI_PracticeAudioProcessorEditor  : public AudioProcessorEditor,
                                          public Slider::Listener

{
public:
    GUI_PracticeAudioProcessorEditor (GUI_PracticeAudioProcessor&);
    ~GUI_PracticeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider * slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    GUI_PracticeAudioProcessor& audioProcessor;
    
    AmpKnob ampKnob;
    MenuKnob menuKnob;
    
    Slider ampSlider;
    Slider menuSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI_PracticeAudioProcessorEditor)
};
