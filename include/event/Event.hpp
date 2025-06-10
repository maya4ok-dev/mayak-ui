namespace mayak {
    enum class EventType {
        None,
        MouseMove,
        MouseDown,
        MouseUp,
        MouseDrag,
        KeyDown,
        KeyUp,
        WindowClose,
        WindowResize,
        WindowMinimalize
    };

    struct Event {
        EventType type = EventType::None;

        int mouseX = 0, mouseY = 0;
        int click = -1;
        int key = -1;
    };

    using EventCallback = void(*)(const Event&e);

    void set_event_callback(EventCallback callback);
    void emit_event(const Event& e);
}