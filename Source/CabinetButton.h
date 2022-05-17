//
//    CabinetButton.h

#pragma once
//
//    CabinetButton.h

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __CabinetButton__
#define __CabinetButton__

//==============================================================================

class CabinetButton : public LookAndFeel_V4
{
public:
    CabinetButton(){};
    virtual ~CabinetButton(){};
    
    virtual void drawToggleButton   (   Graphics &      g,
                                     ToggleButton &     button,
                                     0,
                                     0  )
    {
        
        int buttonSize;
        // 1333, 1334
        auto button = BinaryData::getNamedResource (BinaryData::namedResourceList[1333],buttonSize);
        
        juce::Image image = juce::ImageCache::getFromMemory(button, buttonSize);
        
        g.drawImageAt(image, 0, 0, false);
           
}
  
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CabinetButton);
};

#endif // CabinetButton
