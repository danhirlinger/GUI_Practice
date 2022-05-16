//
//    AmpButton.h

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __AmpKnob__
#define __AmpKnob__

//==============================================================================

class AmpButton : public LookAndFeel_V4
{
public:
    AmpButton(){};
    virtual ~AmpButton(){};
    
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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpButton);
    
};

#endif // AmpButton
