#ifndef AUTH_AUTH_AUTH_H_
#define AUTH_AUTH_AUTH_H_
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "auth_errcode.h"
#ifdef _MSC_VER
#define AUTH_API __declspec(dllexport)
#else
#define AUTH_API
#endif
namespace auth {
#define TRANSITION_PERIOD (3600)
#define CEILING_DAY (90)

class AUTH_API AuthManager {
 public:
  static AuthManager &Instance() {
    static AuthManager auth_;
    return auth_;
  }

  typedef char* (*Callback)(const char* host, const char* port, const char* body);

  void SetDingTalkCallback(Callback callback);

  void SetAssetPath(const char *path);

  static std::string GenTicket(const char *ak_id, const char *ak_secret, const char *app_key, const char *device_id, const char *sdk_code);

  AuthErrorCode DoAuth(const char* ak_id, const char* ak_secret, const char* app_key, const char* device_id, const char* sdk_code);

  const char * GetParam(const char *key);

  AuthErrorCode DoAuth(const std::string &ticket);

  ~AuthManager();

 private:
  AuthManager();
};

}
#endif

