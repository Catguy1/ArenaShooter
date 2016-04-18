// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ArenaShooter.h"
#include "ArenaShooterCharacter.h"
#include "ArenaShooterHUD.h"
#include "Engine/Canvas.h"
#include "TextureResource.h"
#include "CanvasItem.h"

AArenaShooterHUD::AArenaShooterHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshiarTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshiarTexObj.Object;

	static ConstructorHelpers::FObjectFinder<UFont>HUDFontObj(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	Font = HUDFontObj.Object;
}


void AArenaShooterHUD::DrawHUD()
{
	Super::DrawHUD();

	DrawCrosshair();

	DrawHealth();
}

void AArenaShooterHUD::DrawCrosshair()
{
	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),
		(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));

	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}

void AArenaShooterHUD::DrawHealth()
{
	AArenaShooterCharacter * Player = Cast<AArenaShooterCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	int Health = Player->GetCurrentHealth();

	int MaxHealth = Player->GetMaxHealth();

	FString Text = FString::SanitizeFloat(Health) + "/" + FString::SanitizeFloat(MaxHealth);

	FText SomeText = FText::FromString(Text);

	float XPosition = 0;
	float YPosition = Canvas->ClipY*0.9f;

	FLinearColor TheFontColour = FLinearColor(1.0f, 1.0f, 1.0f);
	FCanvasTextItem NewText(FVector2D(XPosition, YPosition), SomeText, Font, TheFontColour);

	//Text Scale
	NewText.Scale.Set(1, 1);

	//Draw
	Canvas->DrawItem(NewText);
}

