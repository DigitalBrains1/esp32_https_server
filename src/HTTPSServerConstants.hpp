#ifndef SRC_HTTPSSERVERCONSTANTS_HPP_
#define SRC_HTTPSSERVERCONSTANTS_HPP_

#include <Arduino.h>

// 1: Error
// 2: Error + Warn
// 3: Error + Warn + Info
// 4: Error + Warn + Info + Debug

#ifndef HTTPS_LOGLEVEL
  #define HTTPS_LOGLEVEL 3
#endif

#if HTTPS_LOGLEVEL > 0
  #ifdef USE_ESP_IDF_LOG
    #define HTTPS_LOGE(...) ESP_LOGE(TAG, ##__VA_ARGS__)
  #else
    #define HTTPS_LOGE(...) log_e(__VA_ARGS__)
  #endif
#else
  #define HTTPS_LOGE(...) do {} while (0)
#endif

#if HTTPS_LOGLEVEL > 1
  #ifdef USE_ESP_IDF_LOG
    #define HTTPS_LOGW(...) ESP_LOGW(TAG, ##__VA_ARGS__)
  #else
    #define HTTPS_LOGW(...) log_w(__VA_ARGS__)
  #endif
#else
  #define HTTPS_LOGW(...) do {} while (0)
#endif

#if HTTPS_LOGLEVEL > 2
  #ifdef USE_ESP_IDF_LOG
    #define HTTPS_LOGI(...) ESP_LOGI(TAG, ##__VA_ARGS__)
  #else
    #define HTTPS_LOGI(...) log_i(__VA_ARGS__)
  #endif
#else
  #define HTTPS_LOGI(...) do {} while (0)
#endif

#if HTTPS_LOGLEVEL > 3
  #ifdef USE_ESP_IDF_LOG
    #define HTTPS_LOGD(...) ESP_LOGD(TAG, ##__VA_ARGS__)
  #else
    #define HTTPS_LOGD(...) log_d(__VA_ARGS__)
  #endif
#else
  #define HTTPS_LOGD(...) do {} while (0)
#endif

// The following lines define limits of the protocol. Exceeding these limits will lead to a 500 error

// Maximum of header lines that are parsed
#ifndef HTTPS_REQUEST_MAX_HEADERS
#define HTTPS_REQUEST_MAX_HEADERS               20
#endif

// Maximum length of the request line (GET /... HTTP/1.1)
#ifndef HTTPS_REQUEST_MAX_REQUEST_LENGTH
#define HTTPS_REQUEST_MAX_REQUEST_LENGTH       128
#endif

// Maximum length of a header line (including name and value)
#ifndef HTTPS_REQUEST_MAX_HEADER_LENGTH
#define HTTPS_REQUEST_MAX_HEADER_LENGTH        384
#endif

// Chunk size used for reading data from the ssl-enabled socket
#ifndef HTTPS_CONNECTION_DATA_CHUNK_SIZE
#define HTTPS_CONNECTION_DATA_CHUNK_SIZE       512
#endif

// Size (in bytes) of the Connection:keep-alive Cache (we need to be able to
// store-and-forward the response to calculate the content-size)
#ifndef HTTPS_KEEPALIVE_CACHESIZE
#define HTTPS_KEEPALIVE_CACHESIZE              1400
#endif

// Timeout for an HTTPS connection without any transmission
#ifndef HTTPS_CONNECTION_TIMEOUT
#define HTTPS_CONNECTION_TIMEOUT               20000
#endif

// Timeout used to wait for shutdown of SSL connection (ms)
// (time for the client to return notify close flag) - without it, truncation attacks might be possible
#ifndef HTTPS_SHUTDOWN_TIMEOUT
#define HTTPS_SHUTDOWN_TIMEOUT                 5000
#endif

// Length of a SHA1 hash
#ifndef HTTPS_SHA1_LENGTH
#define HTTPS_SHA1_LENGTH                      20
#endif

#endif /* SRC_HTTPSSERVERCONSTANTS_HPP_ */
