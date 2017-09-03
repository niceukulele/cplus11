##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=helloworld
ConfigurationName      :=Debug
WorkspacePath          := "/home/wb/workspace/cplus/concurrency/concurrency"
ProjectPath            := "/home/wb/workspace/cplus/concurrency/concurrency/helloworld"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=wb
Date                   :=03/09/17
CodeLitePath           :="/home/wb/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="helloworld.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lc++ -lc++abi -pthread 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)/usr/local/include/clang $(IncludeSwitch)/usr/include/c++/4.8/ $(IncludeSwitch)/usr/include/x86_64-linux-gnu/c++/4.8/ $(IncludeSwitch)/usr/lib/gcc/x86_64-linux-gnu/4.8/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall -pthread  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
LD_LIBRARY_PATH:=/usr/local/lib:$LD_LIBRARY_PATH
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/thread_test.cpp$(ObjectSuffix) $(IntermediateDirectory)/thread_mutex_chapter2.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wb/workspace/cplus/concurrency/concurrency/helloworld/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/thread_test.cpp$(ObjectSuffix): thread_test.cpp $(IntermediateDirectory)/thread_test.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wb/workspace/cplus/concurrency/concurrency/helloworld/thread_test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/thread_test.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/thread_test.cpp$(DependSuffix): thread_test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/thread_test.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/thread_test.cpp$(DependSuffix) -MM "thread_test.cpp"

$(IntermediateDirectory)/thread_test.cpp$(PreprocessSuffix): thread_test.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/thread_test.cpp$(PreprocessSuffix) "thread_test.cpp"

$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(ObjectSuffix): thread_mutex_chapter2.cpp $(IntermediateDirectory)/thread_mutex_chapter2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wb/workspace/cplus/concurrency/concurrency/helloworld/thread_mutex_chapter2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(DependSuffix): thread_mutex_chapter2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(DependSuffix) -MM "thread_mutex_chapter2.cpp"

$(IntermediateDirectory)/thread_mutex_chapter2.cpp$(PreprocessSuffix): thread_mutex_chapter2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/thread_mutex_chapter2.cpp$(PreprocessSuffix) "thread_mutex_chapter2.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


