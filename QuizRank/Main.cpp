# include <Siv3D.hpp> // Siv3D v0.6.12

void Main()
{
	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	// 画像ファイルからテクスチャを作成する | Create a texture from an image file
	const Texture A{ U"engine/01_A.png" };
	const Texture B{ U"engine/02_B.png" };
	const Texture C{ U"engine/03_C.png" };
	const Texture D{ U"engine/04_D.png" };
	const Texture E{ U"engine/05_E.png" };
	const Texture F{ U"engine/06_F.png" };

	Array<Texture> RankCard = {
		A, B, C, D, E, F
	};

	Font font{ FontMethod::MSDF, 48 };

	while (System::Update())
	{
		// Rank Number
		font(U"1").draw(64, 0, 0, Palette::Black);
		font(U"2").draw(64, 0, 90, Palette::Black);
		font(U"3").draw(64, 0, 180, Palette::Black);
		font(U"4").draw(64, 0, 270, Palette::Black);
		font(U"5").draw(64, 0, 360, Palette::Black);
		font(U"6").draw(64, 0, 450, Palette::Black);

		// テクスチャを描く | Draw the texture
		for (int i = 0; i < 6; i++)
		{
			RankCard[i].draw(80, 0 + 90 * i);
		}

		// Replace 1 and 2
		if (SimpleGUI::Button(U"1and2", Vec2{ 700, 80 }))
		{
			RankCard =
			{
							RankCard[1], RankCard[0], RankCard[2], RankCard[3], RankCard[4], RankCard[5]
			};
		}

		// Replace 2 and 3
		if (SimpleGUI::Button(U"2and3", Vec2{ 700, 160 }))
		{
			RankCard =
			{
							RankCard[0], RankCard[2], RankCard[1], RankCard[3], RankCard[4], RankCard[5]
			};
		}

		// Replace 3 and 4
		if (SimpleGUI::Button(U"3and4", Vec2{ 700, 240 }))
		{
			RankCard =
			{
							RankCard[0], RankCard[1], RankCard[3], RankCard[2], RankCard[4], RankCard[5]
			};
		}

		// Replace 4 and 5
		if (SimpleGUI::Button(U"4and5", Vec2{ 700, 320 }))
		{
			RankCard =
			{
							RankCard[0], RankCard[1], RankCard[2], RankCard[4], RankCard[3], RankCard[5]
			};
		}

		// Replace 5 and 6
		if (SimpleGUI::Button(U"5and6", Vec2{ 700, 400 }))
		{
			RankCard =
			{
							RankCard[0], RankCard[1], RankCard[2], RankCard[3], RankCard[5], RankCard[4]
			};
		}
	}
}
