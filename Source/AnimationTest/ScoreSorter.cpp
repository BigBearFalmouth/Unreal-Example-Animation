// Fill out your copyright notice in the Description page of Project Settings.

#include "AnimationTest.h"
#include "ScoreSorter.h"

//overriding the < operator
bool operator <(const FPlayerScore& x, const FPlayerScore& y) {
	return x.Score < y.Score;
}

// Sets default values for this component's properties
UScoreSorter::UScoreSorter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UScoreSorter::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UScoreSorter::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UScoreSorter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	CurrentScores.Empty();
}

//Adds a score, notice the reference
void UScoreSorter::AddScore(const FPlayerScore &Score)
{
	CurrentScores.Add(Score);
}

//Sort sorts the score
void UScoreSorter::Sort()
{
	//this is a predicate anyonmous function without this we would need to overide the < operator for our
	//structure (this is providing our own sorting, if we don't have this it will use < operator)
	/*CurrentScores.Sort([](const FPlayerScore& A, const FPlayerScore& B)
	{
		return A.Score > B.Score;
	});*/

	CurrentScores.Sort();
}

