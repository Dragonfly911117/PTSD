#ifndef UTIL_LOGGER_HPP
#define UTIL_LOGGER_HPP

#include "pch.hpp" // IWYU pragma: export

#include <spdlog/spdlog.h>

namespace Util::Logger {

/**
 * @enum Level
 * @brief Enum representing the logging levels.
 *
 * This enum encapsulates the different levels of logging.
 */
enum class Level {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    ERROR,
    CRITICAL,
};

/**
 * @brief Initializes the logger.
 *
 * This function initializes the logger for the application.
 */
void Init();

/**
 * @brief Sets the logging level.
 *
 * This function sets the logging level for the application.
 *
 * @param level The new logging level.
 */
void SetLevel(Level level);

/**
 * @brief Gets the current logging level.
 *
 * This function returns the current logging level of the application.
 *
 * @return The current logging level.
 */
Level GetLevel();

#define LOG_TRACE(...) spdlog::trace(__VA_ARGS__)
#define LOG_DEBUG(...) spdlog::debug(__VA_ARGS__)
#define LOG_INFO(...) spdlog::info(__VA_ARGS__)
#define LOG_WARN(...) spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...) spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
} // namespace Util::Logger

#endif