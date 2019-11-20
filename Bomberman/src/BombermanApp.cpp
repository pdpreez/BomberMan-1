#include "BombermanApp.hpp"
#include "Swallow/Renderer/material/FlatColourMaterial.hpp"
#include "Swallow/Renderer/material/CharMaterial.hpp"
#include "Swallow/Renderer/texture/TextureMaterial.hpp"
#include "Swallow/AssetManager/AssetManager.hpp"

BombermanApp::BombermanApp(Swallow::WindowProps *props)
	:Swallow::Application(props)
{
	static_cast<void>(props);
	Swallow::FlatColourMaterial::Init();
	Swallow::AnimationMaterial::Init();
	Swallow::CharMaterial::Init();
	Swallow::MenuMaterial::Init();
	Swallow::TextureMaterial::Init();
	Swallow::AssetManager::LoadObject("Bomb", "assets/Models/Bomb.obj");
	Swallow::AssetManager::LoadObject("Bomberman", "assets/Models/BombermanAnim.obj");
	Swallow::AssetManager::LoadObject("BombermanIdle", "assets/Models/BombermanAnimIdle.obj");
	Swallow::AssetManager::LoadObject("Cube", "assets/Models/Cube.obj");
	Swallow::AssetManager::LoadObject("IndestructableWall", "assets/Models/Indestructable_Wall.obj");
	Swallow::AssetManager::LoadObject("DestructableWall", "assets/Models/Destructable_Wall.obj");
	Swallow::AssetManager::LoadObject("EmptyQuad", "assets/Models/EmptyQuad.obj");
	Swallow::AssetManager::LoadTexture("Atlas", "assets/Models/atlas.png", false);
	Swallow::AssetManager::LoadTexture("BomberManColor", "assets/Models/BombermanColor.png", false);

	//Enemies
	//Textures
	Swallow::AssetManager::LoadTexture("EnemyTexture", "assets/Models/Characters/Enemies/Textures/textureAtlas_Enemy.png", false);
	//Models
	Swallow::AssetManager::LoadObject("Enemy", "assets/Models/Characters/Enemies/Enemy.obj");
	


	//Pickups
	//Texture
	Swallow::AssetManager::LoadTexture("PickupsTexture", "assets/Models/Pickups/Pallete1.png", false);
	
	//Models
	Swallow::AssetManager::LoadObject("BombCanBypassWalls", "assets/Models/Pickups/BombCanBypassWalls.obj");
	Swallow::AssetManager::LoadObject("BombUp", "assets/Models/Pickups/BombUp.obj");
	Swallow::AssetManager::LoadObject("BombDown", "assets/Models/Pickups/BombDown.obj");
	Swallow::AssetManager::LoadObject("FireIncrease", "assets/Models/Pickups/FireIncrease.obj");
	Swallow::AssetManager::LoadObject("FireDecrease", "assets/Models/Pickups/FireDecrease.obj");
	Swallow::AssetManager::LoadObject("SpeedDown", "assets/Models/Pickups/SpeedDown.obj");
	Swallow::AssetManager::LoadObject("SpeedUp", "assets/Models/Pickups/SpeedUp.obj");
	Swallow::AssetManager::LoadObject("Key", "assets/Models/Pickups/Key.obj");
	Swallow::AssetManager::LoadObject("SoftBlock", "assets/Models/Pickups/SoftBlock.obj");
	Swallow::AssetManager::LoadObject("Door", "assets/Models/Pickups/Door.obj");
	

	Swallow::AssetManager::ListMeshes("FireIncrease");
	Swallow::AssetManager::ListMeshes("FireDecrease");

	m_Settings = Settings::Create();
	m_GameLayer = std::make_shared<GameLayer>();
	m_GUILayer = std::make_shared<HudMenu>();
	m_MenuLayer = std::make_shared<MainMenu>();
	m_BackgroundLayer = std::make_shared<Background>();
	m_OptionsLayer = std::make_shared<OptionsMenu>();
	m_ExitLayer = std::make_shared<ExitMenu>();
	m_LoadLayer = std::make_shared<LoadingMenu>();
	m_KeyLayer = std::make_shared<KeyMenu>();
	m_NewGameLayer = std::make_shared<NewGame>();
	m_PauseLayer = std::make_shared<PauseMenu>();
	LoadMenu();
}

BombermanApp::~BombermanApp()
{

}

void BombermanApp::UnloadGame()
{
	PopLayer(m_GameLayer);
	PopOverlay(m_GUILayer);
	PopLayer(m_BackgroundLayer);
}

void BombermanApp::LoadGame()
{
	m_GameLayer->SetSpawnChance(m_MenuLayer->GetChance());
	PushLayer(m_BackgroundLayer);
	PushLayer(m_GameLayer);
	PushOverlay(m_GUILayer);
}

Swallow::Application* Swallow::CreateApplication()
{
	Swallow::Ref<Settings> settings = Settings::Create();
	WindowProps p;
	p.Width = settings->GetResolution().x;
	p.Height = settings->GetResolution().y;
	p.Title = "Bomberman";
	return (new BombermanApp(&p));
}

void BombermanApp::LoadMenu()
{
	PushLayer(m_MenuLayer);
}

void BombermanApp::LoadOptions()
{
	PushLayer(m_OptionsLayer);
}

void BombermanApp::LoadLoad()
{
	PushLayer(m_LoadLayer);
}

void BombermanApp::UnloadLoad()
{
	PopLayer(m_LoadLayer);
}

void BombermanApp::UnloadOptions()
{
	PopLayer(m_OptionsLayer);
}

void BombermanApp::LoadExit()
{
	PushLayer(m_ExitLayer);
}

void BombermanApp::UnloadExit()
{
	PopLayer(m_ExitLayer);
}


void BombermanApp::UnloadMenu()
{
	PopLayer(m_MenuLayer);
}

void BombermanApp::LoadKeys()
{
	PushLayer(m_KeyLayer);
}

void BombermanApp::UnloadKeys()
{
	PopLayer(m_KeyLayer);
}

void BombermanApp::LoadNewGame()
{
	PushLayer(m_NewGameLayer);
}

void BombermanApp::UnloadNewGame()
{
	PopLayer(m_NewGameLayer);
}

void BombermanApp::LoadPause()
{
	PushOverlay(m_PauseLayer);
}

void BombermanApp::UnloadPause()
{
	PopOverlay(m_PauseLayer);
}