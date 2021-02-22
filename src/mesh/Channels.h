#pragma once

#include "mesh-pb-constants.h"
#include <Arduino.h>

class Channels
{
    size_t primaryIndex = 0;
    
  public:
    const ChannelSettings &getPrimary() { return getChannel(getPrimaryIndex()).settings; }

    Channel &getChannel(size_t chIndex);

    /** Using the index inside the channel, update the specified channel's settings and role.  If this channel is being promoted to be
     * primary, force all other channels to be secondary.
     */
    void setChannel(const Channel &c);

    const char *getName(size_t chIndex);

    /** The index of the primary channel */
    size_t getPrimaryIndex() const { return primaryIndex; }

    /**
 * Generate a short suffix used to disambiguate channels that might have the same "name" entered by the human but different PSKs.
 * The ideas is that the PSK changing should be visible to the user so that they see they probably messed up and that's why they
their nodes
 * aren't talking to each other.
 *
 * This string is of the form "#name-X".
 *
 * Where X is either:
 * (for custom PSKS) a letter from A to Z (base26), and formed by xoring all the bytes of the PSK together,
 * OR (for the standard minimially secure PSKs) a number from 0 to 9.
 *
 * This function will also need to be implemented in GUI apps that talk to the radio.
 *
 * https://github.com/meshtastic/Meshtastic-device/issues/269
 */
    const char *getPrimaryName();

    /// Called by NodeDB on initial boot when the radio config settings are unset.  Set a default single channel config.
    void initDefaults();

    /// called when the user has just changed our radio config and we might need to change channel keys
    void onConfigChanged();

    /** Given a channel hash setup crypto for decoding that channel (or the primary channel if that channel is unsecured)
     * 
     * This method is called before decoding inbound packets
     * 
     * @return false if no suitable channel could be found.
     */
    bool setCryptoByHash(uint8_t channelHash);

    /** Given a channel index setup crypto for encoding that channel (or the primary channel if that channel is unsecured)
     * 
     * This method is called before encoding inbound packets
     * 
     * @eturn the (0 to 255) hash for that channel - if no suitable channel could be found, return -1
     */
    int16_t setCryptoByIndex(uint8_t channelIndex);

private:
    /** Given a channel index, change to use the crypto key specified by that index
     */
    void setCrypto(size_t chIndex);

    /** Return the channel index for the specified channel hash, or -1 for not found */
    int8_t getChannelIndexByHash(uint8_t channelHash);

    /** Given a channel number, return the (0 to 255) hash for that channel 
     * If no suitable channel could be found, return -1
    */
    int16_t getChannelHash(size_t channelNum);    
};

/// Singleton channel table
extern Channels channels;