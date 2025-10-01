
/*											*/
/*This is a project created by JingLiDeBing */
/*Legend Toolbox                            */
/*First edition:2025.6.11					*/
/*											*/




#include <graphics.h>
#include <windows.h>
#include <winbase.h>
#include <windows.h>
#include <shlobj.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#include <bits/stdc++.h>

#define SHOW_CONSOLE

using namespace std;								//使用标准命名空间

//按钮

struct Button {
	int buttonState = 0;
	bool buttonHaveBackgroundPic = 0;
	int buttonPosX, buttonPosY;
	PIMAGE picButtonBackground;
	int buttonBackgroundPicWidth = getwidth(picButtonBackground), buttonBackgroundPicHeight = getheight(picButtonBackground);
	int buttonWidth, buttonHeight;
	string buttonText; // 添加文字成员变量

	void buttonGetSize()
	{
		if (buttonHaveBackgroundPic == 1) {
			buttonWidth = getwidth(picButtonBackground);
			buttonHeight = getheight(picButtonBackground);
		} else {
			buttonWidth = 50;
			buttonHeight = 50;
		}
		return;
	}

	void buttonPrint()
	{
		if (buttonHaveBackgroundPic == 1) {        //如果按钮有底图
			putimage(buttonPosX, buttonPosY, picButtonBackground);
			buttonBackgroundPicWidth = getwidth(picButtonBackground), buttonBackgroundPicHeight = getheight(picButtonBackground);
			if (buttonState == 0) {
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
			if (buttonState == 1) {
				setlinewidth(3);
				setcolor(GRAY);
				line(buttonPosX, buttonPosY, buttonPosX + buttonBackgroundPicWidth, buttonPosY                                    );
				line(buttonPosX, buttonPosY, buttonPosX, buttonPosY + buttonBackgroundPicHeight - 2    );
				line(buttonPosX + buttonBackgroundPicWidth, buttonPosY, buttonPosX + buttonBackgroundPicWidth, buttonPosY + buttonBackgroundPicHeight - 2    );
				line(buttonPosX, buttonPosY + buttonBackgroundPicHeight - 2, buttonPosX + buttonBackgroundPicWidth, buttonPosY + buttonBackgroundPicHeight - 2     );
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
			if (buttonState == 2) {
				setlinewidth(3);
				setcolor(BLACK);
				line(buttonPosX, buttonPosY, buttonPosX + buttonBackgroundPicWidth, buttonPosY                                    );
				line(buttonPosX, buttonPosY, buttonPosX, buttonPosY + buttonBackgroundPicHeight - 2    );
				line(buttonPosX + buttonBackgroundPicWidth, buttonPosY, buttonPosX + buttonBackgroundPicWidth, buttonPosY + buttonBackgroundPicHeight - 2    );
				line(buttonPosX, buttonPosY + buttonBackgroundPicHeight - 2, buttonPosX + buttonBackgroundPicWidth, buttonPosY + buttonBackgroundPicHeight - 2    );
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
		} else {                                //如果按钮没有底图
			if (buttonState == 0) {
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
			if (buttonState == 1) {
				setlinewidth(3);
				setcolor(GRAY);
				line(buttonPosX, buttonPosY, buttonPosX + buttonWidth, buttonPosY                    );
				line(buttonPosX, buttonPosY, buttonPosX, buttonPosY + buttonHeight - 2 );
				line(buttonPosX + buttonWidth, buttonPosY, buttonPosX + buttonWidth, buttonPosY + buttonHeight - 2 );
				line(buttonPosX, buttonPosY + buttonHeight - 2, buttonPosX + buttonWidth, buttonPosY + buttonHeight - 2 );
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
			if (buttonState == 2) {
				setlinewidth(3);
				setcolor(BLACK);
				line(buttonPosX, buttonPosY, buttonPosX + buttonWidth, buttonPosY                );
				line(buttonPosX, buttonPosY, buttonPosX, buttonPosY + buttonHeight );
				line(buttonPosX + buttonWidth, buttonPosY, buttonPosX + buttonWidth, buttonPosY + buttonHeight );
				line(buttonPosX, buttonPosY + buttonHeight - 3, buttonPosX + buttonWidth, buttonPosY + buttonHeight - 3 );
				// 绘制文字
				setcolor(BLACK);
				outtextxy(buttonPosX + 5, buttonPosY + 5, buttonText.c_str());
				return;
			}
		}
		return;
	}
};

//oldold

//struct Button {
//	int buttonState = 0;
//	bool buttonHaveBackgroundPic = 0;
//	int buttonPosX, buttonPosY;
//	PIMAGE picButtonBackground;
//	int buttonBackgroundPicWidth = getwidth(picButtonBackground), buttonBackgroundPicHeight = getheight(picButtonBackground);
//	int buttonWidth, buttonHeight;
//	void buttonGetSize()
//	{
//		if (buttonHaveBackgroundPic == 1) {
//			buttonWidth = getwidth(picButtonBackground);
//			buttonHeight = getheight(picButtonBackground);
//		} else {
//			buttonWidth = 50;
//			buttonHeight = 50;
//		}
//		return;
//	}
//	void buttonPrint()
//	{
//		if (buttonHaveBackgroundPic == 1) {		//如果按钮有底图
//			putimage(buttonPosX, buttonPosY, picButtonBackground);
//			buttonBackgroundPicWidth = getwidth(picButtonBackground), buttonBackgroundPicHeight = getheight(picButtonBackground);
//			//			xyprintf(0,0,"%d %d",buttonBackgroundPicWidth,buttonBackgroundPicHeight);
//			if (buttonState == 0) {
//				return;
//			}
//			if (buttonState == 1) {
//				setlinewidth(3);
//				setcolor(GRAY);
//				line(buttonPosX								, buttonPosY									, buttonPosX + buttonBackgroundPicWidth, buttonPosY									);
//				line(buttonPosX								, buttonPosY									, buttonPosX							, buttonPosY + buttonBackgroundPicHeight - 2	);
//				line(buttonPosX + buttonBackgroundPicWidth 	, buttonPosY									, buttonPosX + buttonBackgroundPicWidth	, buttonPosY + buttonBackgroundPicHeight - 2	);
//				line(buttonPosX								, buttonPosY + buttonBackgroundPicHeight - 2	, buttonPosX + buttonBackgroundPicWidth, buttonPosY + buttonBackgroundPicHeight - 2 	);
//				return;
//			}
//			if (buttonState == 2) {
//				setlinewidth(3);
//				setcolor(BLACK);
//				line(buttonPosX								, buttonPosY									, buttonPosX + buttonBackgroundPicWidth	, buttonPosY									);
//				line(buttonPosX								, buttonPosY									, buttonPosX							, buttonPosY + buttonBackgroundPicHeight - 2	);
//				line(buttonPosX + buttonBackgroundPicWidth 	, buttonPosY									, buttonPosX + buttonBackgroundPicWidth	, buttonPosY + buttonBackgroundPicHeight - 2	);
//				line(buttonPosX								, buttonPosY + buttonBackgroundPicHeight - 2 	, buttonPosX + buttonBackgroundPicWidth	, buttonPosY + buttonBackgroundPicHeight - 2	);
//				return;
//			}
//		} else {								//如果按钮没有底图
//			if (buttonState == 0) {
//				return;
//			}
//			if (buttonState == 1) {
//				setlinewidth(3);
//				setcolor(GRAY);
//				line(buttonPosX					, buttonPosY					, buttonPosX + buttonWidth 	, buttonPosY					);
//				line(buttonPosX					, buttonPosY					, buttonPosX				, buttonPosY + buttonHeight - 2 );
//				line(buttonPosX + buttonWidth 	, buttonPosY					, buttonPosX + buttonWidth 	, buttonPosY + buttonHeight - 2 );
//				line(buttonPosX					, buttonPosY + buttonHeight - 2	, buttonPosX + buttonWidth 	, buttonPosY + buttonHeight - 2 );
//				return;
//			}
//			if (buttonState == 2) {
//				setlinewidth(3);
//				setcolor(BLACK);
//				line(buttonPosX					, buttonPosY				, buttonPosX + buttonWidth 	, buttonPosY				);
//				line(buttonPosX					, buttonPosY				, buttonPosX				, buttonPosY + buttonHeight );
//				line(buttonPosX + buttonWidth 	, buttonPosY				, buttonPosX + buttonWidth 	, buttonPosY + buttonHeight );
//				line(buttonPosX					, buttonPosY + buttonHeight - 3, buttonPosX + buttonWidth 	, buttonPosY + buttonHeight - 3 );
//				return;
//			}
//		}
//		return;
//	}
//};

int StartStage(PIMAGE, PIMAGE, int, int, int);
void MainStage();
void SidebarPaint(Button, Button, Button, Button, Button, Button, Button);
void openScrapMechanicUserFolder();
void openScrapMechanicUserFolder_CreateProcess();
void CopyToScrapMechanic();
void OverrideGameFile(int fileType = 0);
void OverrideGameFileBackup(int fileType = 0);
mouse_msg MouseMessage();

int windowHeight = 720, windowWidth = 1280;
color_t colorGRAY = EGERGB(127, 127, 127);



int main()
{
	initgraph( windowWidth, windowHeight );							//创建窗口

	/*初始化窗口*/
	setcaption("Legend Toolbox");					//设置窗口标题
	setinitmode(INIT_DEFAULT);						//设置初始化参数
	setbkcolor(WHITE);								//设置绘图背景色
	setbkcolor_f(WHITE);								//设置cleardevice()使用的颜色
	setrendermode(RENDER_MANUAL);					//设置窗口渲染模式
	movewindow(200, 200);							//将窗口位置移动到200，200
	hide_console();									//隐藏控制台界面
	ege_enable_aa(true);							//开启抗锯齿

	/*变量*/
	int graphStage = 1;
	int alpha = 0, flag = 0;
	PIMAGE picWHITEBORED;
	picWHITEBORED = newimage();
	getimage(picWHITEBORED, "resources/picWHITE.png");

	int picWHITEBOREDWidth = getwidth(picWHITEBORED), picWHITEBOREDHeight = getheight(picWHITEBORED);
	PIMAGE picLOGO;
	picLOGO = newimage();
	getimage(picLOGO, "resources/picLogo.png");

	PIMAGE picDemo;
	picDemo = newimage();
	getimage(picDemo, "resources/demo.png");

	//按钮初始化
	Button
	buttonExpand,
	buttonHomePage,
	buttonMotorPoint,
	buttonRestoreMotorPoint,
	buttonChallengeUnlimitedMod,
	buttonChallengeLimitedMod,
	tempbutton;

	//侧边栏展开按钮
	buttonExpand.picButtonBackground = newimage();
	getimage(buttonExpand.picButtonBackground, "resources/picMainStageExpand.png");
	buttonExpand.buttonHaveBackgroundPic = 1;
	buttonExpand.buttonPosX = 0;
	buttonExpand.buttonPosY = 50;
	buttonExpand.buttonGetSize();
	//侧边栏主页按钮
	buttonHomePage.picButtonBackground = newimage();
	getimage(buttonHomePage.picButtonBackground, "resources/picMainStageExpand.png");
	buttonHomePage.buttonHaveBackgroundPic = 1;
	buttonHomePage.buttonPosX = buttonExpand.buttonPosX;
	buttonHomePage.buttonPosY = buttonExpand.buttonPosY + buttonExpand.buttonHeight;
	buttonHomePage.buttonGetSize();
	//开启挑战模式无限制按钮
	buttonChallengeUnlimitedMod.picButtonBackground = newimage();
	getimage(buttonChallengeUnlimitedMod.picButtonBackground, "resources/picMainStageExpand.png");
	buttonChallengeUnlimitedMod.buttonHaveBackgroundPic = 1;
	buttonChallengeUnlimitedMod.buttonPosX = buttonHomePage.buttonPosX;
	buttonChallengeUnlimitedMod.buttonPosY = buttonHomePage.buttonPosY + buttonHomePage.buttonHeight;
	buttonChallengeUnlimitedMod.buttonGetSize();
	//关闭挑战模式无限制按钮
	buttonChallengeLimitedMod.picButtonBackground = newimage();
	getimage(buttonChallengeLimitedMod.picButtonBackground, "resources/picMainStageExpand.png");
	buttonChallengeLimitedMod.buttonHaveBackgroundPic = 1;
	buttonChallengeLimitedMod.buttonPosX = buttonChallengeUnlimitedMod.buttonPosX;
	buttonChallengeLimitedMod.buttonPosY = buttonChallengeUnlimitedMod.buttonPosY + buttonChallengeUnlimitedMod.buttonHeight;
	buttonChallengeLimitedMod.buttonGetSize();
	//更换连线点样式按钮
	buttonMotorPoint.picButtonBackground = newimage();
	getimage(buttonMotorPoint.picButtonBackground, "resources/picApplyMotorPoint.png");
	buttonMotorPoint.buttonHaveBackgroundPic = 1;
	buttonMotorPoint.buttonPosX = 200;
	buttonMotorPoint.buttonPosY = 0;
	buttonMotorPoint.buttonGetSize();
	//恢复默认连线点样式按钮
	buttonRestoreMotorPoint.picButtonBackground = newimage();
	getimage(buttonRestoreMotorPoint.picButtonBackground, "resources/picApplyMotorPoint.png");
	buttonRestoreMotorPoint.buttonHaveBackgroundPic = 1;
	buttonRestoreMotorPoint.buttonPosX = 200;
	buttonRestoreMotorPoint.buttonPosY = buttonMotorPoint.buttonPosY + buttonMotorPoint.buttonHeight;
	buttonRestoreMotorPoint.buttonGetSize();


	//临时按钮
	tempbutton.picButtonBackground = newimage();
	getimage(tempbutton.picButtonBackground, "resources/picMainStageExpand.png");
	tempbutton.buttonHaveBackgroundPic = 1;
	tempbutton.buttonPosX = 0, tempbutton.buttonPosY = 0;
	tempbutton.buttonGetSize();


	/*--------------------------------------------------------------------------------------------*/
	//	ShellExecute(NULL, "open", "open.cmd", NULL, NULL, SW_SHOW);		//文件方式打开
	for ( ; is_run(); delay_fps(120) ) {

		/*图形处理*/
		switch (graphStage) {
			case 1: {								//开幕动画
				if (flag == 1 && alpha <= 255)
					alpha += 2;
				if (flag == 3 && alpha >= 0)
					alpha -= 2;
				break;
			}
			case 2: {
				//鼠标消息处理
				mouse_msg tempMouseMessage;
				tempMouseMessage = MouseMessage();
				//
				if (	tempMouseMessage.x >= buttonExpand.buttonPosX && tempMouseMessage.x <= buttonExpand.buttonPosX + buttonExpand.buttonWidth &&
				        tempMouseMessage.y >= buttonExpand.buttonPosY && tempMouseMessage.y <= buttonExpand.buttonPosY + buttonExpand.buttonHeight) {
					buttonExpand.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonExpand.buttonState = 2;
					}
				} else {
					buttonExpand.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= buttonHomePage.buttonPosX && tempMouseMessage.x <= buttonHomePage.buttonPosX + buttonHomePage.buttonWidth &&
				        tempMouseMessage.y >= buttonHomePage.buttonPosY && tempMouseMessage.y <= buttonHomePage.buttonPosY + buttonHomePage.buttonHeight) {
					buttonHomePage.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonHomePage.buttonState = 2;
					}
				} else {
					buttonHomePage.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= tempbutton.buttonPosX && tempMouseMessage.x <= tempbutton.buttonPosX + tempbutton.buttonWidth &&
				        tempMouseMessage.y >= tempbutton.buttonPosY && tempMouseMessage.y <= tempbutton.buttonPosY + tempbutton.buttonHeight) {
					tempbutton.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						tempbutton.buttonState = 2;
					}
				} else {
					tempbutton.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= buttonMotorPoint.buttonPosX && tempMouseMessage.x <= buttonMotorPoint.buttonPosX + buttonMotorPoint.buttonWidth &&
				        tempMouseMessage.y >= buttonMotorPoint.buttonPosY && tempMouseMessage.y <= buttonMotorPoint.buttonPosY + buttonMotorPoint.buttonHeight) {
					buttonMotorPoint.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonMotorPoint.buttonState = 2;
					}
				} else {
					buttonMotorPoint.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= buttonRestoreMotorPoint.buttonPosX && tempMouseMessage.x <= buttonRestoreMotorPoint.buttonPosX + buttonRestoreMotorPoint.buttonWidth &&
				        tempMouseMessage.y >= buttonRestoreMotorPoint.buttonPosY && tempMouseMessage.y <= buttonRestoreMotorPoint.buttonPosY + buttonRestoreMotorPoint.buttonHeight) {
					buttonRestoreMotorPoint.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonRestoreMotorPoint.buttonState = 2;
					}
				} else {
					buttonRestoreMotorPoint.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= buttonChallengeUnlimitedMod.buttonPosX && tempMouseMessage.x <= buttonChallengeUnlimitedMod.buttonPosX + buttonChallengeUnlimitedMod.buttonWidth &&
				        tempMouseMessage.y >= buttonChallengeUnlimitedMod.buttonPosY && tempMouseMessage.y <= buttonChallengeUnlimitedMod.buttonPosY + buttonChallengeUnlimitedMod.buttonHeight) {
					buttonChallengeUnlimitedMod.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonChallengeUnlimitedMod.buttonState = 2;
					}
				} else {
					buttonChallengeUnlimitedMod.buttonState = 0;
				}
				//
				if (	tempMouseMessage.x >= buttonChallengeLimitedMod.buttonPosX && tempMouseMessage.x <= buttonChallengeLimitedMod.buttonPosX + buttonChallengeLimitedMod.buttonWidth &&
				        tempMouseMessage.y >= buttonChallengeLimitedMod.buttonPosY && tempMouseMessage.y <= buttonChallengeLimitedMod.buttonPosY + buttonChallengeLimitedMod.buttonHeight) {
					buttonChallengeLimitedMod.buttonState = 1;
					if (tempMouseMessage.is_down() && tempMouseMessage.is_left()) {
						buttonChallengeLimitedMod.buttonState = 2;
					}
				} else {
					buttonChallengeLimitedMod.buttonState = 0;
				}



			}
			break;
		}

		/*绘制*/
		cleardevice();
		switch (graphStage) {
			case 1: {							//开场动画绘制
				if (flag == 0) {
					delay(1000);
					flag = 1;
					break;
				}
				if (flag == 1) {
					StartStage(picLOGO, picWHITEBORED, picWHITEBOREDWidth, picWHITEBOREDHeight, alpha);
					if (alpha >= 255)
						flag = 2;
				}
				if (flag == 2) {
					StartStage(picLOGO, picWHITEBORED, picWHITEBOREDWidth, picWHITEBOREDHeight, 255);
					delay(1000);
					flag = 3;
				}
				if (flag == 3) {
					StartStage(picLOGO, picWHITEBORED, picWHITEBOREDWidth, picWHITEBOREDHeight, alpha);
					if (alpha <= 0)
						flag = 4;
				}
				if (flag == 4) {
					graphStage = 2;
					delimage(picLOGO);
				}
				break;
			}
			case 2: {							//主页面绘制
				SidebarPaint(buttonExpand, buttonHomePage, buttonMotorPoint, buttonRestoreMotorPoint, buttonChallengeUnlimitedMod, buttonChallengeLimitedMod, tempbutton);
				MainStage();
				putimage(450, 40, picDemo);
				if (buttonHomePage.buttonState == 2) {
					openScrapMechanicUserFolder();//打开存档目录
					delay(10);
				}

				if (buttonExpand.buttonState == 2) {
					OverrideGameFile(0); // 替换SurvivalGame.lua
					delay(10);
				}
				if (tempbutton.buttonState == 2) {
					OverrideGameFileBackup(0); // 恢复SurvivalGame.lua
					delay(10);
				}
				if (buttonMotorPoint.buttonState == 2) {
					OverrideGameFile(1); // 替换motorpoint.png
					delay(10);
				}
				if (buttonRestoreMotorPoint.buttonState == 2) {
					OverrideGameFileBackup(1); // 恢复motorpoint.png
					delay(10);
				}
				if (buttonChallengeUnlimitedMod.buttonState == 2) {
					OverrideGameFile(2); // 替换ChallengeGame.lua
					delay(10);
				}
				if (buttonChallengeLimitedMod.buttonState == 2) {
					OverrideGameFileBackup(2); // 恢复ChallengeGame.lua
					delay(10);
				}
			}
		}

	}
	getch();
	return 0;
}


/*函数*/
int StartStage(PIMAGE picLogo, PIMAGE picWHITE, int picWHITEBOREDwidth, int picWHITEBOREDHeight, int alpha)
{
	//	color_t tempColor = EGERGB(255, 255, 255);
	//	int picLogoWidth = getwidth(picLogo), picLogoHeight = getheight(picLogo);
	//淡入
	//	putimage_alphablend(
	//	    picLogo, picWHITE,
	//	    0, 0,
	//	    alpha,
	//	    0, 0,
	//	    picLogoWidth, picLogoHeight
	//	);
	//	putimage(0,0,picLogo);
	putimage_alphablend(NULL, picLogo, 0, 0, alpha);
	return 2;
}




void MainStage()
{
	xyprintf(60, 15, "关闭生存开发者");
	xyprintf(60, 65, "开启生存开发者");
	xyprintf(260, 15, "替换连线点样式");
	xyprintf(260, 65, "恢复默认连线点");
	xyprintf(60, 115, "打开存档路径");
	xyprintf(60, 165, "开启挑战模式无限物品模式");
	xyprintf(60, 215, "关闭挑战模式无限物品模式");
	xyprintf(400, 15, "注意！请在游戏启动选项中输入命令-dev以应用连线点样式更换！该操作只需执行一次即可");
	xyprintf(400, 40, "如图:");
	line(390, 0, 390, windowHeight);
	return;
}



void SidebarPaint(Button Expand, Button HomePage, Button ApplyMotorPoint, Button RestoreMotorPoint, Button ChallengeUnimitedMod, Button ChallengeLimitedMod, Button temp)
{
	Expand.buttonPrint();
	HomePage.buttonPrint();
	ApplyMotorPoint.buttonPrint();
	RestoreMotorPoint.buttonPrint();
	ChallengeUnimitedMod.buttonPrint();
	ChallengeLimitedMod.buttonPrint();
	temp.buttonPrint();
	return;
}


mouse_msg MouseMessage()
{
	//当消息队列中有鼠标时，读取鼠标消息并进行处理
	mouse_msg MouseMsg;
	while (mousemsg()) {
		MouseMsg = getmouse();
	}
	return MouseMsg;
}



void openScrapMechanicUserFolder()
{
	// 获取环境变量
	char userProfile[MAX_PATH];
	GetEnvironmentVariableA("USERPROFILE", userProfile, MAX_PATH);

	// 构造带引号的路径
	char path[MAX_PATH * 2];
	snprintf(path, sizeof(path),
	         "\"%s\\AppData\\Roaming\\Axolot Games\\Scrap Mechanic\\User\"",
	         userProfile);

	// 使用explorer.exe打开
	ShellExecuteA(NULL, "open", "explorer.exe", path, NULL, SW_SHOW);
	return;
}

void openScrapMechanicUserFolder_CreateProcess()
{
	char cmd[MAX_PATH * 3];
	snprintf(cmd, sizeof(cmd),
	         "explorer.exe \"%%USERPROFILE%%\\AppData\\Roaming\\Axolot Games\\Scrap Mechanic\\User\"");

	STARTUPINFOA si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hThread);
	return;
}


//void CopyToScrapMechanic() {
//	// 获取程序根目录
//	char exePath[MAX_PATH];
//	GetModuleFileNameA(NULL, exePath, MAX_PATH);
//	std::string rootDir(exePath);
//	rootDir = rootDir.substr(0, rootDir.find_last_of("\\/"));
//
//	// 源文件路径
//	std::string source = rootDir + "\\resources\\SurvivalGame.lua";
//
//	// 目标路径（Scrap Mechanic 默认位置）
//	CHAR userProfile[MAX_PATH];
//	GetEnvironmentVariableA("USERPROFILE", userProfile, MAX_PATH);
//	std::string dest = std::string(userProfile) +
//	"\\AppData\\Roaming\\Axolot Games\\Scrap Mechanic\\User\\SurvivalGame.lua";
//
//	// 执行复制
//	CopyFileA(source.c_str(), dest.c_str(), FALSE);
//	return;
//}



void OverrideGameFile(int fileType) // 0 = SurvivalGame.lua, 1 = motorpoint.png, 2 = ChallengeGame.lua
{
	// 获取源文件路径
	char exePath[MAX_PATH];
	GetModuleFileNameA(NULL, exePath, MAX_PATH);
	char* lastSlash = strrchr(exePath, '\\');
	if (lastSlash) *lastSlash = '\0';

	string sourcePath;
	if (fileType == 0) {
		sourcePath = string(exePath) + "\\resources\\SurvivalGame.lua";
	}
	if (fileType == 1) {
		sourcePath = string(exePath) + "\\resources\\motorpoint.png";
	}
	if (fileType == 2) {
		sourcePath = string(exePath) + "\\resources\\ChallengeGame.lua";
	}

	// 获取 Steam 安装路径
	char steamPath[MAX_PATH] = {0};
	DWORD size = MAX_PATH;
	if (RegGetValueA(HKEY_CURRENT_USER, "Software\\Valve\\Steam",
	                 "SteamPath", RRF_RT_REG_SZ, NULL, steamPath, &size) != ERROR_SUCCESS)
		return;

	// 查找所有 Steam 库
	vector<string> libraries = { steamPath };
	string vdfPath = string(steamPath) + "\\steamapps\\libraryfolders.vdf";

	HANDLE hFile = CreateFileA(vdfPath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
	                           OPEN_EXISTING, 0, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		char buf[4096] = {0};
		DWORD bytesRead;
		ReadFile(hFile, buf, sizeof(buf) - 1, &bytesRead, NULL);
		CloseHandle(hFile);

		string content = buf;
		size_t pos = 0;
		while ((pos = content.find("\"path\"", pos)) != string::npos) {
			pos += 6;
			size_t start = content.find('\"', pos) + 1;
			size_t end = content.find('\"', start);
			if (end == string::npos) break;

			libraries.push_back(content.substr(start, end - start));
			pos = end;
		}
	}

	// 覆盖所有可能的游戏路径
	for (const auto& lib : libraries) {
		string target;
		if (fileType == 0) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\Survival\\Scripts\\game\\SurvivalGame.lua";
		}
		if (fileType == 1) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\Data\\Textures\\ConnectTool\\motorpoint.png";
		}
		if (fileType == 2) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\ChallengeData\\Scripts\\challenge\\ChallengeGame.lua";
		}
		CopyFileA(sourcePath.c_str(), target.c_str(), FALSE);
	}
	return;
}

void OverrideGameFileBackup(int fileType) // 0 = SurvivalGame.lua, 1 = motorpoint.png
{
	// 获取源文件路径
	char exePath[MAX_PATH];
	GetModuleFileNameA(NULL, exePath, MAX_PATH);
	char* lastSlash = strrchr(exePath, '\\');
	if (lastSlash) *lastSlash = '\0';

	string sourcePath;
	if (fileType == 0) {
		sourcePath = string(exePath) + "\\resources\\backup\\SurvivalGame.lua";
	}
	if (fileType == 1) {
		sourcePath = string(exePath) + "\\resources\\motorpoint.png";
	}
	if (fileType == 2) {
		sourcePath = string(exePath) + "\\resources\\ChallengeGame.lua";
	}

	// 获取 Steam 安装路径
	char steamPath[MAX_PATH] = {0};
	DWORD size = MAX_PATH;
	if (RegGetValueA(HKEY_CURRENT_USER, "Software\\Valve\\Steam",
	                 "SteamPath", RRF_RT_REG_SZ, NULL, steamPath, &size) != ERROR_SUCCESS)
		return;

	// 查找所有 Steam 库
	vector<string> libraries = { steamPath };
	string vdfPath = string(steamPath) + "\\steamapps\\libraryfolders.vdf";

	HANDLE hFile = CreateFileA(vdfPath.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL,
	                           OPEN_EXISTING, 0, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		char buf[4096] = {0};
		DWORD bytesRead;
		ReadFile(hFile, buf, sizeof(buf) - 1, &bytesRead, NULL);
		CloseHandle(hFile);

		string content = buf;
		size_t pos = 0;
		while ((pos = content.find("\"path\"", pos)) != string::npos) {
			pos += 6;
			size_t start = content.find('\"', pos) + 1;
			size_t end = content.find('\"', start);
			if (end == string::npos) break;

			libraries.push_back(content.substr(start, end - start));
			pos = end;
		}
	}

	// 覆盖所有可能的游戏路径
	for (const auto& lib : libraries) {
		string target;
		if (fileType == 0) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\Survival\\Scripts\\game\\SurvivalGame.lua";
		}
		if (fileType == 1) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\Data\\Textures\\ConnectTool\\motorpoint.png";
		}
		if (fileType == 2) {
			target = lib + "\\steamapps\\common\\Scrap Mechanic\\ChallengeData\\Scripts\\challenge\\ChallengeGame.lua";
		}
		CopyFileA(sourcePath.c_str(), target.c_str(), FALSE);
	}
	return;
}
