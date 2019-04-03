void print_main();//主界面命令提示
void print_admin();//管理员界面命令提示
void print_user();//用户界面命令提示

void set_position(int x, int y);//句柄设置

void print_admin_non_order();//无命令时，界面显示

int check_password();//管理员界面登录密码验证
void print_admin_music_list();//曲库修改命令提示

//曲库管理
void add_music_once();//单次添加
void remove_music_once();//单次删除
void add_music_list();//列表式添加

//选歌系统
void print_user_choose_music();