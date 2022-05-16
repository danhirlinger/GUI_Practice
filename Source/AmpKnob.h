//
//  AmpKnob.h

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __AmpKnob__
#define __AmpKnob__

//==============================================================================

class AmpKnob : public LookAndFeel_V4 // inherit from LookAndFeel_V4
{
public:
    
    AmpKnob(){};
    virtual ~AmpKnob(){};
    
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
        
        /// keep the below here for future reference
//        auto arr = BinaryData::namedResourceList;
//        int n = sizeof(arr)/sizeof(arr[0]);
//        auto elem = "amp_knob_0000_png";
//
//        auto itr = std::find(arr, arr + n, elem);
//
//        int offset = std::distance(arr,itr);
        /// keep the above here for future reference
        
        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); ///value between 0 and 1 for current amount of rotation
        
        int offsetFactor = 0; /// the placement order of the files relative to the other files in the BinaryData
        int numFrames = 128;
        
        const int frameIdx = (ceil(fractRotation * numFrames) + (numFrames)*offsetFactor); /// the index value based upon the fractional rotation and the location of the files in the BinaryData (offsetFactor)
        
        int knobSize;
        auto knob = BinaryData::getNamedResource (BinaryData::namedResourceList[frameIdx], knobSize);
        
        juce::Image image = juce::ImageCache::getFromMemory(knob, knobSize);
        
        g.drawImageAt(image, 0, 0, false);

    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpKnob);
};

#endif   // AmpKnob
