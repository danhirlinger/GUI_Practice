//
//  MenuKnob.h
//
//  Copyright © 2020 Eric Tarr. All rights reserved.
//  Code may not be distributed without permission
//
//  This class was created to override and customize the LookAndFeel of the default JUCE components
//

#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>
//#include <algorithm>

#ifndef __MenuKnob__
#define __MenuKnob__

//==============================================================================

class MenuKnob : public LookAndFeel_V4 // inherit from LookAndFeel_V4
{
public:
    
    MenuKnob(){};
    virtual ~MenuKnob(){};
    
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
        
        /// idea taken from algorithm found on below website
        /// https://www.techiedelight.com/find-index-element-array-cpp/
        
        auto arr = BinaryData::namedResourceList;
        int n = sizeof(arr)/sizeof(arr[0]);
        auto elem = "menu_knob_0000_png";
        
        auto itr = std::find(arr, arr + n, elem);
        
        auto offset = std::distance(arr,itr);
        
        const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); ///value between 0 and 1 for current amount of rotation
        
        
//        const int frameIdx = (int)ceil(fractRotation * ((BinaryData::namedResourceListSize) - 1));
        const int frameIdx = (int)ceil(fractRotation * ((130) - 1)+offset);
        // Original current index from 0 --> namedResourceListSize-1
        // Need to alter framing index when there are multiple knobs in resourceList
        
        // Goal: take the file name and find its beginning index in binaryData.h
        // find the beginning index of the file name, and then add that index number to the frameIdx
        
        /// Create strings of the file name, allowing for the index number of the file name to be variable
///        String filename1 = "menu_knob_";
///        String filename2 = "_png";
///        String armadillo = std::to_string(frameIdx);
///        auto totalSize = filename1.String::length() + armadillo.String::length() + filename2.String::length();

        // Would like to have a function that can find the index of the start of the files, rather than gather the binary data using the file name with the function "BinaryData::originalFilenames"
        
///         set a string = menu_knob_0000_png
///         set a loop for the length of the namedResourceListSize
///         within loop, search through namedResourceList array for the string name and its respective index in the array
///         once found, extract the index number from that position. This is the number that gets added onto the frameIdx
        
        ///  ^^ this will probably be too much CPU, unless we could implement this in the constructor
        
        
//        char filename[] = {filename1, frameIdx, filename2};
//        concatStrings(filename,filename1,frameIdx,filename2);
        
        // BinaryData::namedResourceList[frameIdx]
        // ^^ returns the binary data of the image as well as its size
        
        // BinaryData::getNamedResourceOriginalFilename(cow);
        // ^^ returning the file name
        
        // BinaryData::originalFilenames['menu_knob_0000_png'];
        // ^^ returning the binary data of the image
        
        auto knob = BinaryData::getNamedResource (BinaryData::namedResourceList[frameIdx], knobSize);
        
        juce::Image image = juce::ImageCache::getFromMemory(knob, knobSize);
        
        g.drawImageAt(image, 0, 0, false);
        
    }
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MenuKnob);
};

#endif   // MenuKnob
