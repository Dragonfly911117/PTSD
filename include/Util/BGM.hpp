#ifndef UTIL_BGM_HPP
#define UTIL_BGM_HPP
#include <SDL_mixer.h>
#include <memory>
#include <string>
namespace Util {
/**
 * @class BGM
 * @brief Class for handling background music.
 * @note There can be only one BGM object playing at a time.
 *      If a BGM object is playing and another BGM object is played,
 *      the previous one will stop playing.
 */
class BGM {
public:
    /**
     * @brief Default constructor for creating a BGM object.
     * @note This constructor does not load any media.
     *       The LoadMedia() function <b>MUST</b> be called afterward.
     */
    BGM() = default;

    /**
     * @brief Constructor that initializes the BGM object and loads the music
     * from the specified file path.
     * @param path The file path of the background music to be loaded.
     */
    BGM(const std::string &path);

    /**
     * @brief Deleted copy assignment operator to prevent copying of BGM
     * objects.
     */
    BGM &operator=(const BGM &) = delete;

    /**
     * @brief Deleted copy constructor to prevent copying of BGM objects.
     */
    BGM(const BGM &) = delete;

    /**
     * @brief Retrieves the current volume of the background music.
     * @return The current volume of the background music.
     */
    int GetVolume() const;

    /**
     * @brief Sets the volume of the background music.
     * @param volume The desired volume level for the background music. The
     * valid range is [0, 128]. <br>
     * A value of 0 mutes the music, and a value of 128
     * sets the maximum volume.
     */
    void SetVolume(const int &volume);

    /**
     * @brief Loads the background music from the specified file path.
     * @param path The file path of the background music to be loaded.
     */
    void LoadMedia(const std::string &path);

    /**
     * @brief Increases the volume of the background music by one.
     */
    void VolumeUp();

    /**
     * @brief Decreases the volume of the background music by one.
     */
    void VolumeDown();

    /**
     * @brief Plays the background music.
     * @param loop The number of times the music will loop.<br>
     *             A value of -1 means it will loop indefinitely.<br>
     *             A non-negative value means it will loop that many times.<br>
     *             Default value: -1
     * @note Calling this function stops any currently playing music and plays.
     */
    void Play(const int &loop = -1);

    /**
     * @brief Fades in the background music gradually.
     * @param tick The duration of the fade-in effect, in milliseconds.
     * @param loop The number of times the music will loop after the fade-in is
     * complete.<br> A value of -1 means it will loop indefinitely.
     */
    void FadeIn(const int &tick, const int &loop = -1);

    /**
 * @brief Pauses the currently playing background music.
 * @note This function has no effect if there is no background music currently playing.
     */
    void Pause();

    /**
 * @brief Resumes the paused background music.
 * @note This function has no effect if there is no paused background music.
     */
    void Resume();


private:
    std::unique_ptr<Mix_Music, void (*)(Mix_Music *)> m_BGM =
        std::unique_ptr<Mix_Music, void (*)(Mix_Music *)>(nullptr,
                                                          Mix_FreeMusic);
};

} // namespace Util

#endif // UTIL_BGM_HPP