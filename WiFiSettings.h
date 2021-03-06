#ifndef WiFiSettings_h
#define WiFiSettings_h

#include <Arduino.h>
#include <functional>

class WiFiSettingsClass {
    public:
        typedef std::function<void(void)> TCallback;
        typedef std::function<int(void)> TCallbackInt;

        WiFiSettingsClass();
        void begin();
        bool connect(bool portal = true, int wait_seconds = 30);
        void portal();
        String string(String name, String init = "", String label = "");
        String string(String name, unsigned int max_length, String init = "", String label = "");
        String string(String name, unsigned int min_length, unsigned int max_length, String init = "", String label = "");
        long integer(String name, long init = 0, String label = "");
        long integer(String name, long min, long max, long init = 0, String label = "");
        bool checkbox(String name, bool init = false, String label = "");

        String hostname;
        String password;
        bool secure;

        TCallback onConnect;
        TCallbackInt onWaitLoop;
        TCallback onSuccess;
        TCallback onFailure;
        TCallback onPortal;
        TCallback onConfigSaved;
        TCallback onRestart;
        TCallback onPortalWaitLoop;
    private:
        bool begun;
};

extern WiFiSettingsClass WiFiSettings;

#endif
