//
//  EQKnob.h

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __EQKnob__
#define __EQKnob__

//==============================================================================

class EQKnob : public LookAndFeel_V4 // inherit from LookAndFeel_V4
{
public:
    
    EQKnob(){};
    virtual ~EQKnob(){};
    
    virtual void drawRotarySlider    (    Graphics &     g,
                                      int     x,
                                      int     y,
                                      int     width,
                                      int     height,
                                      float     sliderPosProportional,
                                      float     rotaryStartAngle,
                                      float     rotaryEndAngle,
                                      Slider &     slider )
    {
        
        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); ///value between 0 and 1 for current amount of rotation
        
        int offsetFactor = 3; /// the placement order of the files relative to the other files in the BinaryData
        int numFrames = 128;

        const int frameIdx = (ceil(fractRotation * numFrames) + (numFrames+1)*offsetFactor); /// the index value based upon the fractional rotation and the location of the files in the BinaryData (offsetFactor)

        int knobSize;
        auto knob = BinaryData::getNamedResource (BinaryData::namedResourceList[frameIdx], knobSize);
        
        juce::Image image = juce::ImageCache::getFromMemory(knob, knobSize);
        
        g.drawImageAt(image, 0, 0, false);

    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EQKnob);
};

#endif   // EQKnob
