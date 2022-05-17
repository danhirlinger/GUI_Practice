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
    setSize (800, 400);
    
    amp.setBounds(50,50,100,100);
    amp.setRange(1.f,100.f,.1f);
    amp.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    amp.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    amp.setSize(160,160);
    amp.setLookAndFeel(&ampKnob);
    addAndMakeVisible(amp);
    
    chorus.setBounds(200,50,100,100);
    chorus.setRange(1.f,100.f,.1f);
    chorus.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    chorus.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    chorus.setSize(160,160);
    chorus.setLookAndFeel(&chorusKnob);
    addAndMakeVisible(chorus);
    
    echo.setBounds(350,50,100,100);
    echo.setRange(1.f,100.f,.1f);
    echo.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    echo.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    echo.setSize(160,160);
    echo.setLookAndFeel(&echoKnob);
    addAndMakeVisible(echo);
    
    eq.setBounds(500,50,100,100);
    eq.setRange(1.f,100.f,.1f);
    eq.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    eq.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    eq.setSize(160,160);
    eq.setLookAndFeel(&eqKnob);
    addAndMakeVisible(eq);
    
    menu.setBounds(50,250,100,100);
    menu.setRange(1.f,100.f,.1f);
    menu.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    menu.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    menu.setSize(160,160);
    menu.setLookAndFeel(&menuKnob);
    addAndMakeVisible(menu);
    
    mxr.setBounds(200,250,100,100);
    mxr.setRange(1.f,100.f,.1f);
    mxr.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    mxr.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    mxr.setSize(160,160);
    mxr.setLookAndFeel(&mxrKnob);
    addAndMakeVisible(mxr);
    
    reverb.setBounds(350,250,100,100);
    reverb.setRange(1.f,100.f,.1f);
    reverb.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    reverb.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    reverb.setSize(160,160);
    reverb.setLookAndFeel(&reverbKnob);
    addAndMakeVisible(reverb);
    
    ts.setBounds(500,250,100,100);
    ts.setRange(1.f,100.f,.1f);
    ts.setTextBoxStyle(Slider::TextBoxRight, false, 75, 25);
    ts.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    ts.setSize(160,160);
    ts.setLookAndFeel(&tsKnob);
    addAndMakeVisible(ts);
    
    ampSwitchOn.setBounds(700,150,100,100);
    addAndMakeVisible(ampSwitchOn);
    
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
//    g.drawFittedText ("Amp on left, menu on right", getLocalBounds(), juce::Justification::centred, 1);
}

void GUI_PracticeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void GUI_PracticeAudioProcessorEditor::sliderValueChanged(Slider * slider){
    
}

void GUI_PracticeAudioProcessorEditor::buttonClicked(Button * button){
    
}
