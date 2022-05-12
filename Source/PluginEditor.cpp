/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GUI_PracticeAudioProcessorEditor::GUI_PracticeAudioProcessorEditor (GUI_PracticeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    ampSlider.setBounds(100,100,100,100);
    ampSlider.setRange(1.f,100.f,.1f);
    ampSlider.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    ampSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    ampSlider.setSize(160,160);
    ampSlider.setLookAndFeel(&ampKnob);
    addAndMakeVisible(ampSlider);
    
    
    menuSlider.setBounds(200,100,100,100);
    menuSlider.setRange(1.f,100.f,.1f);
    menuSlider.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    menuSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    menuSlider.setSize(160,160);
    menuSlider.setLookAndFeel(&menuKnob);
    addAndMakeVisible(menuSlider);
}

GUI_PracticeAudioProcessorEditor::~GUI_PracticeAudioProcessorEditor()
{
}

//==============================================================================
void GUI_PracticeAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void GUI_PracticeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void GUI_PracticeAudioProcessorEditor::sliderValueChanged(Slider * slider){
    
}
