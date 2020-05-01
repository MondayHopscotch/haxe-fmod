/**
* Faxe - FMOD bindings for Haxe
*
* The MIT License (MIT)
*
* Copyright (c) 2016 Aaron M. Shea
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#define IMPLEMENT_API

#if (defined __MWERKS__)
	#include <SIOUX.h>
#endif

#include <fmod_studio.hpp>

namespace linc
{
	namespace faxe
	{
		//// Baisc FMOD operations

		/**
		 * Initialization of FMOD sound system
		 * \param[numChannels] number of channels to allocate for this sound system
		 */
		extern void faxe_init(int numChannels = 32);

		extern void faxe_set_debug(bool onOff);
		
		/**
		 * Update the FMOD command buffer, should be called once per "tick"
		 */
		extern void faxe_update();

		/**
		 * Clean up allocated objects from the FMOD sound system
		 */
		extern void faxe_shutdown();

		//// Sound + Bank operations

		/**
		 * Load a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to load
		 */
		extern void faxe_load_bank(const ::String& bankName);

		/**
		 * Unload a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to unload
		 */
		extern void faxe_unload_bank(const ::String& bankName);
		
		//// Event operations

		/**
		 * Load an event instance from a loaded bank
		 * \param[eventPath] ::String the path of the event
		 * \param[eventName] ::String the name you wish to give this event instance
		 */
		extern void faxe_load_event_instance(const ::String& eventPath, const ::String& eventName);

		/**
		 * Load an event description from a loaded bank
		 * \param[eventPath] ::String the path of the event
		 * \param[eventName] ::String the name you wish to give this event description
		 */
		extern void faxe_load_event_description(const ::String& eventPath, const ::String& eventName);

		/**
		 * Check if an event instance is currently loaded
		 * \param[eventName] ::String the event instance to check
		 */
		extern bool faxe_is_event_instance_loaded(const ::String& eventName);

		/**
		 * Check if an event description is currently loaded
		 * \param[eventName] ::String the event description to check
		 */
		extern bool faxe_is_event_description_loaded(const ::String& eventName);

		/**
		 * Play an already-loaded event instance
		 * \param[eventName] ::String the name of the event to play
		 */
		extern void faxe_play_event_instance(const ::String& eventName);

		/**
		 * Set the pause state of an event instance
		 * \param[eventName] ::String the name of the event instance
		 * \param[shouldBePaused] bool if the event instance should be paused
		 */
		extern void faxe_set_pause_on_event_instance(const ::String& eventName, bool shouldBePaused);

		/**
		 * Play an already-loaded event description as a fire-and-forget event
		 * \param[eventName] ::String the name of the event to play
		 */
		extern void faxe_play_one_shot(const ::String& eventName);

		/**
		 * Play an already loaded event
		 * \param[eventName] ::String the name of the event to play
		 * \param[forceStop] ::Bool should we force the event to stop immediately?
		 */
		extern void faxe_stop_event(const ::String& eventName, bool forceStop = false);

		/**
		 * Release a loaded event
		 * \param[eventName] ::String the name of the event to release
		 */
		extern void faxe_release_event(const ::String& eventName);

		/**
		 * Check to see if an event is currently playing
		 * \param[eventName] ::String the name of the event to check playing status of
		 * \return ::Bool if the event is currently playing
		 */
		extern bool faxe_is_event_playing(const ::String& eventName);

		/**
		 * Get the status of an existing event
		 * \param[eventName] ::String the name of the event to check playing status of
		 */
		extern FMOD_STUDIO_PLAYBACK_STATE faxe_get_event_playback_state(const ::String& eventName);

		/**
		 * Check to see if an event is currently playing
		 * \param[eventName] ::String the name of the event to get param value from
		 * \param[paramName] ::String the name of the param to GET
		 * \return float the current value of the param from the specified event
		 */
		extern float faxe_get_event_param(const ::String& eventName, const ::String& paramName);

		/**
		 * Set the parameter value of a loaded event
		 * \param[eventName] ::String the name of the event that contains the parameter to set
		 * \param[paramName] ::String the name of the param to SET
		 * \param[sValue] float the new value to set the param to
		 */
		extern void faxe_set_event_param(const ::String& eventName, const ::String& paramName, float sValue);

		//// Channel operations
		extern void faxe_stop_all_channels();
		extern void faxe_stop_channel(int channelID);
		extern void faxe_set_channel_gain(int channelID, float gainDb);
		extern void faxe_set_channel_position(int channelID, float x, float y, float z);
		extern bool faxe_channel_playing(int channelID);
		
		extern FMOD::System* faxe_get_system();

	} // faxe + fmod namespace
} // linc namespace
