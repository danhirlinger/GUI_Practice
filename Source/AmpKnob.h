//
//  AmpKnob.h
//
//  Copyright © 2020 Eric Tarr. All rights reserved.
//  Code may not be distributed without permission
//
//  This class was created to override and customize the LookAndFeel of the default JUCE components
//

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __AmpKnob__
#define __AmpKnob__

//==============================================================================
// There are two options, Big White Knob with (below) and without the blue outline.
// Just inherit the desired LookAndFeel
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
        
        int knobSize;
        
        /// Width and height of object comes from above "drawRotarySlider"
///        const int nFrames = 256; //knob.getHeight()/knob.getWidth(); // number of frames for vertical film strip
        
        auto arr = BinaryData::namedResourceList;
        int n = sizeof(arr)/sizeof(arr[0]);
        auto elem = "amp_knob_0000_png";
        
        auto itr = std::find(arr, arr + n, elem);
        
        int offset = std::distance(arr,itr);
        
        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); ///value between 0 and 1 for current amount of rotation
        
        
//        const int frameIdx = (int)ceil(fractRotation * ((BinaryData::namedResourceListSize) - 1));
        const char frameIdx = (int)ceil(fractRotation * (129 - 1)+offset);
        // Original current index from 0 --> namedResourceListSize-1
        // Will need to alter framing index when there are multiple knobs in resourceList
        // RIght now is assumed image has index of 0-128
        
        auto knob = BinaryData::getNamedResource (BinaryData::namedResourceList[frameIdx], knobSize);
        
        juce::Image image = juce::ImageCache::getFromMemory(knob, knobSize);
        
        g.drawImageAt(image, 0, 0, false);
        
        
        // graphics module not liking that I am trying to feed const char data type into juce::Image
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpKnob);
};

#endif   // AmpKnob
