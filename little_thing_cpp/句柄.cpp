void set_position(int x, int y){
    HANDLE win_handle;
    COORD pos = {x, y};
    win_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(win_handle,pos);
}