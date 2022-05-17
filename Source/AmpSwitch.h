//
//    AmpSwitch.h

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef __AmpSwitch__
#define __AmpSwitch__

//==============================================================================

class AmpSwitch : public ImageButton
{
public:
    AmpSwitch(){
        Colour c = Colour((uint8)0,(uint8)0,(uint8)0,(uint8)0);
        
        int sizeN = BinaryData::amp_button_off_pngSize;
        int sizeD = BinaryData::amp_button_on_pngSize;
        
        auto imageN = BinaryData::getNamedResource (BinaryData::namedResourceList[1032],sizeN);
        auto imageD = BinaryData::getNamedResource (BinaryData::namedResourceList[1033],sizeD);
        
        juce::Image imgN = juce::ImageCache::getFromMemory(imageN, sizeN);
        juce::Image imgD = juce::ImageCache::getFromMemory(imageD, BinaryData::amp_button_on_pngSize);
        
        setImages(true, true, true, imgN, 0.8, c, imgN, 0.8, c, imgD, 0.8, c);
        
        setClickingTogglesState(true);
    };
    
    virtual ~AmpSwitch(){};
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmpSwitch);
};

#endif // AmpSwitch
