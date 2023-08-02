#pragma once
#include <iostream>
#include <chrono>

struct Timer {
	
	std::chrono::time_point<std::chrono::high_resolution_clock> begin, end;
	std::chrono::duration<float> duration;

	void start() {
		begin = std::chrono::high_resolution_clock::now();
	}

	float stop() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - begin;

		float duration_ms = duration.count() * 1000.0f;
		return duration_ms;
	}

};
