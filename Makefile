clean:
	@rm -rf *.~ *.o

ffmpeg:
	@git clone https://github.com/FFmpeg/FFmpeg.git
	@cd FFmpeg && ./configure && make -j4 && make install -j4

a.out: main.c ffmpeg
	@gcc main.c -L./ffmpeg-4.1/libavcodec/libavcodec

run: a.out
	@./a.out video.flv processed.flv
