//#include <iostream>
//using namespace std;
//
//#include <Windows.h>
//#include <thread> // Not in the tutorial but required to get sleep command working
//#include <chrono> // Same as above
//#include <vector>
//
//wstring tetromino[7]; // Tetris blocks are called tetrominos
//int nFieldWidth = 12;
//int nFieldHeight = 18;
//unsigned char* pField = nullptr;
//
//int nScreenWidth = 120;         // This one was causing all of our problems as Windows has a unique way of handling console sizes
//int nScreenHeight = 30;         // Console Screen Size Y (rows)
//
//int Rotate(int px, int py, int r)
//{
//	switch (r % 4)
//	{
//	case 0: return py * 4 + px;         // 0 degrees 
//	case 1: return 12 + py - (px * 4);  // 90 degrees
//	case 2: return 15 - (py * 4) - px;  // 180 degrees
//	case 3: return 3 - py + (px * 4);   // 270 degrees
//	}
//	return 0;
//}
//
//bool DoesPieceFit(int nTetromino, int nRotation, int nPosX, int nPosY)
//{
//	for (int px = 0; px < 4; px++)
//		for (int py = 0; py < 4; py++)
//		{
//			// Get index into piece
//			int pi = Rotate(px, py, nRotation);
//
//			// Get index into field
//			int fi = (nPosY + py) * nFieldWidth + (nPosX + px);
//
//			if (nPosX + px >= 0 && nPosX + px < nFieldWidth)
//			{
//				if (nPosY + py >= 0 && nPosY + py < nFieldHeight)
//				{
//					if (tetromino[nTetromino][pi] == L'X' && pField[fi] != 0)
//						return false; // fail on first hit
//				}
//			}
//		}
//
//
//	return true;
//}
//
//int main()
//{
//	// create assests
//	tetromino[0].append(L"..X.");
//	tetromino[0].append(L"..X.");
//	tetromino[0].append(L"..X.");
//	tetromino[0].append(L"..X."); // I-Block
//
//	tetromino[1].append(L"..X.");
//	tetromino[1].append(L".XX.");
//	tetromino[1].append(L".X..");
//	tetromino[1].append(L"...."); // S-Block
//
//	tetromino[2].append(L".X..");
//	tetromino[2].append(L".XX.");
//	tetromino[2].append(L"..X.");
//	tetromino[2].append(L"...."); // Z-Block
//
//	tetromino[3].append(L"....");
//	tetromino[3].append(L".XX.");
//	tetromino[3].append(L".XX.");
//	tetromino[3].append(L"...."); // O-Block
//
//	tetromino[4].append(L"..X.");
//	tetromino[4].append(L".XX.");
//	tetromino[4].append(L"..X.");
//	tetromino[4].append(L"...."); // T-Block
//
//	tetromino[5].append(L"....");
//	tetromino[5].append(L"..X.");
//	tetromino[5].append(L"..X.");
//	tetromino[5].append(L".XX."); // J-Block
//
//	tetromino[6].append(L"....");
//	tetromino[6].append(L".X..");
//	tetromino[6].append(L".X..");
//	tetromino[6].append(L".XX."); // L-Block
//
//	pField = new unsigned char[nFieldWidth * nFieldHeight]; // Create play field buffer
//	for (int x = 0; x < nFieldWidth; x++) // Board Boundary
//		for (int y = 0; y < nFieldHeight; y++)
//			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;
//
//	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
//	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';
//	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//	SetConsoleActiveScreenBuffer(hConsole);
//	DWORD dwBytesWritten = 0;
//
//
//	// Game Logic Stuff
//	bool bGameOver = false;
//
//	int nCurrentPiece = 6;
//	int nCurrentRotation = 0;
//	int nCurrentX = nFieldWidth / 2;
//	int nCurrentY = 0;
//
//	bool bKey[4];
//	bool bRotateHold = false;
//
//	int nSpeed = 20;
//	int nSpeedCount = 0;
//	bool bForceDown = false;
//	int nPieceCount = 0;
//	int nScore = 0;
//
//	vector<int> vLines;
//
//	while (!bGameOver)
//	{
//		// GAME TIME ===================================
//		std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Game Tick
//		nSpeedCount++;
//		bForceDown = (nSpeedCount == nSpeed);
//
//		// INPUT =======================================
//		for (int k = 0; k < 4; k++)                           //   R   L   D   
//			bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("\x27\x25\x28\x26"[k]))) != 0;
//
//		// GAME LOGIC ==================================
//		nCurrentX += (bKey[0] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX + 1, nCurrentY)) ? 1 : 0;
//		nCurrentX -= (bKey[1] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX - 1, nCurrentY)) ? 1 : 0;
//		nCurrentY += (bKey[2] && DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1)) ? 1 : 0;
//
//		if (bKey[3]) // I switched the rotate key as it felt more convenient with the buttons closr together
//		{
//			nCurrentRotation += (!bRotateHold && DoesPieceFit(nCurrentPiece, nCurrentRotation + 1, nCurrentX, nCurrentY)) ? 1 : 0;
//			bRotateHold = true;
//		}
//		else
//			bRotateHold = false;
//
//
//		if (bForceDown)
//		{
//			if (DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY + 1))
//				nCurrentY++; // It can move
//			else
//			{
//				// Lock piece in field
//				for (int px = 0; px < 4; px++)
//					for (int py = 0; py < 4; py++)
//						if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
//							pField[(nCurrentY + py) * nFieldWidth + (nCurrentX + px)] = nCurrentPiece + 1;
//
//				nPieceCount++;
//				if (nPieceCount % 10 == 0)
//					if (nSpeed >= 10) nSpeed--;
//
//				// Check for line clears
//				for (int py = 0; py < 4; py++)
//					if (nCurrentY + py < nFieldHeight - 1)
//					{
//						bool bLine = true;
//						for (int px = 1; px < nFieldWidth - 1; px++)
//							bLine &= (pField[(nCurrentY + py) * nFieldWidth + px]) != 0;
//						if (bLine)
//						{
//							// Remove Line, set to =
//							for (int px = 1; px < nFieldWidth - 1; px++)
//								pField[(nCurrentY + py) * nFieldWidth + px] = 8;
//
//							vLines.push_back(nCurrentY + py);
//						}
//					}
//
//				nScore += 25;
//				if (!vLines.empty()) nScore += (1 << vLines.size()) * 100;
//
//				// Choose next piece
//				nCurrentX = nFieldWidth / 2;
//				nCurrentY = 0;
//				nCurrentRotation = 0;
//				nCurrentPiece = rand() % 7;
//
//				// If piece does not fit
//				bGameOver = !DoesPieceFit(nCurrentPiece, nCurrentRotation, nCurrentX, nCurrentY);
//			}
//
//			nSpeedCount = 0;
//		}
//
//		// RENDER OUTPUT ===============================
//
//		// Draw Field
//		for (int x = 0; x < nFieldWidth; x++)
//			for (int y = 0; y < nFieldHeight; y++)
//				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];
//
//		// Draw Current Piece
//		for (int px = 0; px < 4; px++)
//			for (int py = 0; py < 4; py++)
//				if (tetromino[nCurrentPiece][Rotate(px, py, nCurrentRotation)] == L'X')
//					screen[(nCurrentY + py + 2) * nScreenWidth + (nCurrentX + px + 2)] = nCurrentPiece + 65;
//
//		// Draw Score
//		swprintf_s(&screen[2 * nScreenWidth + nFieldWidth + 6], 16, L"SCORE: %8d", nScore);
//
//		if (!vLines.empty())
//		{
//			// Display Frame to draw lines
//			WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
//			std::this_thread::sleep_for(std::chrono::milliseconds(400)); // Delay a bit
//
//			for (auto& v : vLines)
//				for (int px = 1; px < nFieldWidth - 1; px++)
//				{
//					for (int py = v; py > 0; py--)
//						pField[py * nFieldWidth + px] = pField[(py - 1) * nFieldWidth + px];
//					pField[px] = 0;
//				}
//
//			vLines.clear();
//		}
//
//		// Display Frame
//		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
//	}
//
//	// Game Over
//	CloseHandle(hConsole);
//	cout << "Game Over!! Score: " << nScore << endl;
//	system("pause");
//
//	return 0;
//}
