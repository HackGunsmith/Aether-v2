// Random humanized delay (used in aim + triggerbot)
float HumanDelay() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(7.4f, 21.9f);
    return dist(gen);
}

// Bone randomizer every 8-19 ticks
int GetRandomBone() {
    static int tick_counter = 0;
    static int current_bone = 8; // head

    if (++tick_counter > rand() % 11 + 8) {
        current_bone = (current_bone == 8) ? 6 : 8; // head ↔ neck
        tick_counter = 0;
    }
    return current_bone;
}
