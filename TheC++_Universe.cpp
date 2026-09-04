// ============================================================
// MINI-SCRIPT 03: THE MEMORY UNIVERSE
// (Matrix ops shifts to mini_04 — this lesson is more foundational.)
//
// TEACHES:  stack vs heap, pointers, references, new/delete,
//           leaks, dangling pointers, RAII, unique_ptr/shared_ptr/
//           weak_ptr, move semantics, noexcept, Rule of Zero/Five,
//           and sanitizers as professional proof of correctness.
// MAPS TO:  YOUR metaphor — corrected, sharpened, and compiled:
//
//   ┌─────────────────────────┬──────────────────────────────────┐
//   │ Your picture            │ C++ reality                      │
//   ├─────────────────────────┼──────────────────────────────────┤
//   │ The desk                │ the stack (automatic storage)    │
//   │ The open land           │ the heap (dynamic storage)       │
//   │ Commissioning a building│ new / make_unique                │
//   │ The huskelapp           │ a raw pointer (coordinates)      │
//   │ Losing the huskelapp    │ memory leak (immortal building)  │
//   │ Note to demolished bldg │ dangling pointer (UB)            │
//   │ Invite to your desk     │ reference (&)                    │
//   │ Deed w/ self-destruct   │ unique_ptr (RAII)                │
//   │ Co-op deed              │ shared_ptr (ref-counted)         │
//   │ Note that KNOWS if the  │ weak_ptr (.expired())            │
//   │   building still stands │                                  │
//   │ Transferring the deed   │ std::move (voids the old one)    │
//   │ LIF / coordinate chart  │ scope (valid only in its patch)  │
//   └─────────────────────────┴──────────────────────────────────┘
//
// PROJECT:  → every allocation decision in cpp/src/solvers/.
//           Matrix3cd (fixed 3×3)  → desk.
//           Runtime-sized ensembles → land, via std::vector.
//
// COMPILE:  g++ -std=c++17 -O2 -Wall -Wextra mini_03_memory_universe.cpp -o mini_03
// RUN:      ./mini_03
// VERIFY:   g++ -std=c++17 -g -fsanitize=address mini_03_memory_universe.cpp -o mini_03_asan
//           ./mini_03_asan     ← the pro move: the tool NAMES the leaked building
// ============================================================

#include <iostream>
#include <iomanip>
#include <memory>     // unique_ptr, shared_ptr, weak_ptr, make_unique/make_shared
#include <string>
#include <vector>
#include <chrono>     // the copy-vs-move stopwatch
#include <utility>    // std::move
#include <cstddef>    // std::size_t

namespace QuantumGrav {

// ────────────────────────────────────────────────────────────
// §0  THE INSTRUMENTED BUILDING
//
// Every construction, copy, move, and demolition PRINTS ITSELF.
// This makes the invisible visible: when you run the program,
// the console narrates your metaphor in real time.
//
// The Building owns an expensive interior: a pile of bricks
// (std::vector<double>) that itself lives on the heap. This is
// the key to understanding copy vs move:
//   COPY  = build a second building, duplicating every brick.
//   MOVE  = transfer the deed; the brick pile changes owner;
//           ZERO bricks are touched. The old object becomes a
//           hollow shell, trivially swept away later.
// ────────────────────────────────────────────────────────────
class Building {
public:
    // `explicit` forbids silent conversions like:  Building b = "oops";
    // A building is commissioned deliberately or not at all.
    explicit Building(std::string name, std::size_t n_bricks = 4)
        : name_(std::move(name))          // (a taste of §6: steal the caller's string)
        , bricks_(n_bricks, 1.0)
        , id_(++total_built_)
    {
        ++standing_;
        std::cout << "    [BUILD]    #" << id_ << " '" << name_ << "' commissioned ("
                  << bricks_.size() << " bricks)   standing=" << standing_ << "\n";
    }

    // COPY CONSTRUCTOR — a replica, brick by brick. Expensive and loud.
    Building(const Building& other)
        : name_(other.name_ + "*copy")
        , bricks_(other.bricks_)          // ← every single brick duplicated
        , id_(++total_built_)
    {
        ++standing_;
        ++copies_;
        std::cout << "    [COPY]     #" << id_ << " replica of '" << other.name_
                  << "' built brick-by-brick (" << bricks_.size() << " bricks)\n";
    }

    // MOVE CONSTRUCTOR — the deed transfer. O(1). No bricks touched.
    //
    // `noexcept` here is NOT decoration. std::vector, when it grows and must
    // relocate its Buildings, will only use your move constructor if it
    // PROMISES not to throw — otherwise the vector copies for exception
    // safety. Forget noexcept and your "fast" moves silently become copies.
    // This one keyword is a classic senior-level interview question.
    Building(Building&& other) noexcept
        : name_(std::move(other.name_))
        , bricks_(std::move(other.bricks_))   // internally: three pointers swap. That's ALL.
        , id_(other.id_)                       // the deed number travels with the deed
    {
        ++standing_;
        ++moves_;
        other.name_ = "<hollow shell>";
        std::cout << "    [MOVE]     deed of #" << id_
                  << " transferred; 0 bricks touched\n";
    }

    // Some buildings are not for sale: you can FORBID operations outright.
    // (Assignment is deleted here purely to keep this lesson focused on
    //  construction and destruction.)
    Building& operator=(const Building&) = delete;
    Building& operator=(Building&&)      = delete;

    // DESTRUCTOR — the demolition crew. Runs AUTOMATICALLY for stack
    // objects at scope exit, and for heap objects when delete / a smart
    // pointer fires. A hollow shell (post-move) demolishes for free.
    ~Building() {
        --standing_;
        if (bricks_.empty())
            std::cout << "    [SWEEP]    hollow shell of #" << id_
                      << " cleared (nothing inside)   standing=" << standing_ << "\n";
        else
            std::cout << "    [DEMOLISH] #" << id_ << " '" << name_
                      << "'   standing=" << standing_ << "\n";
    }

    void renovate(const std::string& wing) { name_ += wing; }
    [[nodiscard]] const std::string& name() const { return name_; }

    // Static bookkeeping — the city registry.
    [[nodiscard]] static int standing() { return standing_; }
    [[nodiscard]] static int total()    { return total_built_; }
    [[nodiscard]] static int copies()   { return copies_; }
    [[nodiscard]] static int moves()    { return moves_; }

private:
    std::string          name_;
    std::vector<double>  bricks_;   // the expensive interior (heap-backed)
    int                  id_;

    // C++17 inline statics: define counters right here in the class.
    static inline int total_built_ = 0;
    static inline int standing_    = 0;
    static inline int copies_      = 0;
    static inline int moves_       = 0;
};

void header(const std::string& title) {
    std::cout << "\n══════════════════════════════════════════════════════\n"
              << "  " << title << "\n"
              << "══════════════════════════════════════════════════════\n";
}

// ────────────────────────────────────────────────────────────
// §1  THE DESK (stack) — your local inertial frame
//
// Physics mapping, made precise: a scope { } is a coordinate
// patch. Everything you declare inside is valid ONLY within it,
// managed automatically, and torn down in reverse order (LIFO)
// the instant the brace closes — like Riemann normal coordinates
// that lose meaning away from the point where you erected them.
// ────────────────────────────────────────────────────────────
void the_desk() {
    header("§1  THE DESK — automatic, scoped, self-cleaning");

    int    a = 1;
    double b = 2.0;
    char   c = 'q';

    // Addresses are the "coordinates" you suspected pointers were.
    // Watch: desk items sit side by side — neighbors in one stack frame.
    std::cout << "  coordinates on the desk (one stack frame):\n";
    std::cout << "    &a = " << static_cast<const void*>(&a) << "\n";
    std::cout << "    &b = " << static_cast<const void*>(&b) << "\n";
    std::cout << "    &c = " << static_cast<const void*>(&c) << "\n\n";

    std::cout << "  opening an inner scope { ... } — a nested experiment:\n";
    {
        Building first("DeskLab_A");
        Building second("DeskLab_B");
        std::cout << "  ...work happens...\n";
        // NO delete. NO cleanup code. Watch what the closing brace does,
        // and note the ORDER: B falls before A. Last built, first demolished.
    }
    std::cout << "  ← the brace closed. Demolition happened WITHOUT you.\n"
              << "    That is automatic storage: the desk cleans itself.\n";
}

// ────────────────────────────────────────────────────────────
// §2  THE LAND (heap) — commissioned, not scavenged
//
// THE CORRECTION to your original picture: the heap is not a
// garbage pile of pre-existing impure objects. It is EMPTY LAND.
// Nothing exists there until YOU commission it with `new`, and
// what you get back is fresh. The price: nobody demolishes it
// but you. C++ has no roaming demolition service (Java/Python's
// garbage collector is exactly that service — C++ skips it for speed).
// ────────────────────────────────────────────────────────────
void the_land_raw() {
    header("§2  THE LAND — new/delete, the raw (pre-modern) way");

    // Commission a building on the land. `new` returns its coordinates,
    // which you write on a huskelapp. THE NOTE ITSELF LIVES ON YOUR DESK.
    Building* note = new Building("HeapLab", 8);

    std::cout << "\n  the huskelapp is a desk object:  &note = "
              << static_cast<const void*>(&note) << "   (desk coordinates)\n";
    std::cout << "  what's WRITTEN on it:             note = "
              << static_cast<const void*>(note)  << "   (land coordinates)\n";
    std::cout << "  compare with §1's desk addresses — different neighborhood entirely.\n\n";

    note->renovate("+east_wing");             // visit the building via the note
    std::cout << "  renovated: '" << note->name() << "'\n";

    delete note;      // YOU are the demolition crew. Miss this = leak.
    note = nullptr;   // void the note so it can't dangle. Defensive habit.
    std::cout << "  demolished by hand, note voided. This works — but every\n"
              << "  `new` now carries a lifelong obligation. §5 removes it.\n";
}

// ────────────────────────────────────────────────────────────
// §3  THE BUG GALLERY — the four classic memory crimes
// ────────────────────────────────────────────────────────────
void bug_gallery() {
    header("§3  THE BUG GALLERY — each crime, named in your language");

    // ── BUG 1: THE LOST HUSKELAPP (memory leak) ─────────────────────────
    // We commit this one FOR REAL, deliberately, exactly once — so the
    // final report counts it and AddressSanitizer can name it at exit.
    //
    // Note the correction: the leak does NOT corrupt anything. The
    // building stands, fully functional, forever — powered, heated,
    // unreachable. Do this in a loop and the city runs out of land.
    std::cout << "  BUG 1 — the lost huskelapp (LEAK), committed on purpose:\n";
    Building* lost = new Building("LEAKED_Reactor", 4);
    lost = nullptr;   // ← the ONLY note, overwritten. Coordinates gone forever.
    std::cout << "    the note now reads: " << static_cast<const void*>(lost)
              << "  → the Reactor is immortal and unreachable.\n"
              << "    (no crash, no corruption — just land lost. Run the ASan\n"
              << "     build and the sanitizer prints its allocation site.)\n\n";

    // ── BUG 2: THE DEMOLISHED BUILDING (dangling pointer / use-after-free) ──
    // This one we must NOT run: it is undefined behavior — trusting rubble.
    //
    //     Building* d = new Building("Ghost");
    //     delete d;                // demolition
    //     d->renovate("+wing");    // ← visiting the rubble. ANYTHING may happen.
    //
    // ASan would report:  heap-use-after-free
    // THIS is the bug your original "impurities" intuition was describing —
    // a different crime from the leak, debugged with different tools.
    std::cout << "  BUG 2 — dangling pointer: shown in source, never executed (UB).\n\n";

    // ── BUG 3: CHART BEYOND ITS PATCH (returning a local's address) ────────
    //
    //     int* escape() { int local = 42; return &local; }
    //
    // The desk item dies at the brace; the returned coordinates point at a
    // dismantled stack frame. Your LIF analogy is exact: valid coordinates,
    // dead patch. GCC refuses politely — real output from this compiler:
    //
    //     warning: address of local variable 'local' returned [-Wreturn-local-addr]
    //
    std::cout << "  BUG 3 — returning a desk address: the compiler itself objects.\n\n";

    // ── BUG 4: DOUBLE DEMOLITION ────────────────────────────────────────
    //
    //     delete p;
    //     delete p;    // ← demolishing rubble. UB. ASan: double-free.
    //
    // The `p = nullptr;` habit from §2 neutralizes this one, because
    // `delete nullptr;` is defined as a harmless no-op.
    std::cout << "  BUG 4 — double delete: neutralized by the nullptr habit of §2.\n";
}

// ────────────────────────────────────────────────────────────
// §4  REFERENCES — three ways to let someone at your building
//
// Pass by VALUE      → a replica materializes on THEIR desk.
// Pass by CONST REF  → they visit YOUR desk; may look, not touch.
// Pass by REF        → they visit YOUR desk; renovate the real thing.
//
// The instrumentation makes this undeniable: watch which call
// triggers a [COPY] line. Exactly one will.
// ────────────────────────────────────────────────────────────
void visit_by_value(Building guest) {                 // replica built HERE
    std::cout << "      (by value)     I received '" << guest.name() << "'\n";
}   // ...and the replica is demolished right here, at this brace.

void visit_by_const_ref(const Building& guest) {      // no copy; read-only
    std::cout << "      (by const ref) I can see '" << guest.name()
              << "' but may not touch it\n";
    // guest.renovate("+x");   // ← would not compile: const forbids it
}

void visit_by_ref(Building& guest) {                  // no copy; full access
    guest.renovate("+ref_wing");
    std::cout << "      (by ref)       I renovated the ORIGINAL: '"
              << guest.name() << "'\n";
}

void references_tour() {
    header("§4  REFERENCES — value vs const& vs &  (watch for [COPY])");
    Building original("RefLab", 6);
    std::cout << "\n  calling visit_by_value(original):\n";
    visit_by_value(original);
    std::cout << "\n  calling visit_by_const_ref(original):\n";
    visit_by_const_ref(original);
    std::cout << "\n  calling visit_by_ref(original):\n";
    visit_by_ref(original);
    std::cout << "\n  one [COPY], one [DEMOLISH] of the replica — and the const&/&\n"
              << "  visits cost NOTHING. This is why your hot paths pass const&.\n";
}

// ────────────────────────────────────────────────────────────
// §5  SMART DEEDS — RAII: ownership made structural
//
// The pre-modern land (§2) relied on DISCIPLINE: remember to
// delete. RAII replaces discipline with STRUCTURE: the deed
// itself carries a self-destruct clause bound to scope.
// This is the single most important idea in professional C++:
//
//     Resource Acquisition Is Initialization —
//     lifetime of the resource == lifetime of the owning object.
// ────────────────────────────────────────────────────────────
void smart_deeds() {
    header("§5  SMART DEEDS — unique_ptr, shared_ptr, weak_ptr");

    // ── unique_ptr: THE SOLE DEED ───────────────────────────────────────
    std::cout << "  unique_ptr — sole ownership:\n";
    {
        auto deed = std::make_unique<Building>("SmartLab", 8);
        std::cout << "    land coordinates via deed.get() = "
                  << static_cast<const void*>(deed.get()) << "\n";

        // A sole deed cannot be photocopied. Real compiler output:
        //   error: use of deleted function 'std::unique_ptr<_Tp,_Dp>::
        //          unique_ptr(const std::unique_ptr<_Tp,_Dp>&)'
        // auto illegal = deed;                    // ← does not compile

        auto heir = std::move(deed);               // deed TRANSFER (legal)
        std::cout << "    after std::move: old deed is "
                  << (deed ? "still valid (?!)" : "VOIDED (nullptr)")
                  << ", heir holds the building.\n";
    }   // ← heir leaves scope → demolition fires AUTOMATICALLY.
    std::cout << "    scope closed: demolition ran, and `delete` appears NOWHERE.\n\n";

    // ── shared_ptr + weak_ptr: THE CO-OP DEED and THE HONEST NOTE ────────
    std::cout << "  shared_ptr — co-owned deed with a live counter:\n";
    std::weak_ptr<Building> watcher;   // a note that KNOWS if the building stands
    {
        auto coop = std::make_shared<Building>("CoopTower", 8);
        watcher = coop;
        std::cout << "    deed holders: " << coop.use_count() << "\n";
        {
            auto partner = coop;   // copying the DEED — note: NO [COPY] line!
                                   // The deed was photocopied; the building was not.
            std::cout << "    partner joined  → holders: " << coop.use_count() << "\n";
        }
        std::cout << "    partner left    → holders: " << coop.use_count() << "\n";
        std::cout << "    watcher.expired()? " << std::boolalpha
                  << watcher.expired() << "  (building stands)\n";
    }   // ← last holder leaves → demolition fires.
    std::cout << "    watcher.expired()? " << std::boolalpha << watcher.expired()
              << "   (the note KNOWS the building fell — dangling, cured)\n";
}

// ────────────────────────────────────────────────────────────
// §6  MOVE SEMANTICS — the deed transfer, measured
//
// std::move does not move anything. It is a CAST — a formal
// declaration: "I hereby void my claim; take everything."
// The move constructor then does the actual transfer: for a
// vector, three pointers swap owners. Ten million bricks or
// three — same cost. Let's prove it with a stopwatch.
// ────────────────────────────────────────────────────────────
void move_benchmark() {
    header("§6  MOVE vs COPY — the stopwatch does not lie");

    using clk = std::chrono::steady_clock;
    constexpr std::size_t N = 10'000'000;          // 10M doubles = 80 MB of bricks

    std::vector<double> mega(N, 3.14);
    std::cout << "  a brick pile of " << N << " doubles (" << (N * 8) / 1'000'000
              << " MB) sits on the land.\n\n";

    auto t0 = clk::now();
    std::vector<double> replica = mega;            // COPY: duplicate every brick
    auto t1 = clk::now();
    std::vector<double> stolen  = std::move(mega); // MOVE: swap three pointers
    auto t2 = clk::now();

    const double copy_us = std::chrono::duration<double, std::micro>(t1 - t0).count();
    const double move_us = std::chrono::duration<double, std::micro>(t2 - t1).count();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  COPY  (brick-by-brick):  " << std::setw(12) << copy_us << " µs\n";
    std::cout << "  MOVE  (deed transfer):   " << std::setw(12) << move_us << " µs\n";
    std::cout << "  ratio:                    ~" << static_cast<long>(copy_us / std::max(move_us, 0.01))
              << "× — and the gap GROWS with N; the move is O(1).\n\n";

    // Observable use so the optimizer can't discard the work:
    std::cout << "  (checks: replica.back()=" << replica.back()
              << ", stolen.front()=" << stolen.front()
              << ", mega.size()=" << mega.size()
              << " ← valid but empty: the voided deed)\n\n";

    std::cout << "  PROJECT PAYOFF: your EngineSolver's `return pp1;` (a big\n"
              << "  vector<double>) is FREE — guaranteed move or elided entirely\n"
              << "  (NRVO). Your Python instinct that returning big objects is\n"
              << "  expensive is simply false in modern C++.\n\n";

    // And at Building level — watch the deed transfer narrate itself.
    // Note what a moved-from object IS: valid but hollowed. We defined its
    // state ourselves in the move ctor, so reading it here is legitimate.
    std::cout << "  Building-level deed transfer, live:\n";
    {
        Building original("MoveLab", 8);
        Building successor(std::move(original));      // ← [MOVE] fires here
        std::cout << "    successor holds '" << successor.name()
                  << "'; original is now '" << original.name() << "'\n";
    }   // ← successor demolished normally; the shell swept for free.
}

// ────────────────────────────────────────────────────────────
// §7  THE RULE OF ZERO — the pinnacle
//
// Building (§0) manages a resource, so it defines the special
// operations: destructor + copy + move. That's the RULE OF FIVE,
// and it belongs ONLY in resource-manager classes.
//
// Everything ABOVE that layer should obey the RULE OF ZERO:
// hold resources in RAII members (vector, string, unique_ptr)
// and write NO destructor, NO copy, NO move, NO delete — the
// compiler-generated ones are correct BECAUSE every member
// already knows how to clean itself.
//
// The pinnacle of professional C++ is code where `delete`
// never appears — not because you remembered every site,
// but because the design left nothing to remember.
// ────────────────────────────────────────────────────────────
class NVEnsemble {
public:
    explicit NVEnsemble(std::size_t n) {
        centers_.reserve(n);   // pre-buy the land: no mid-construction reallocations
                               // (your EngineSolver already does exactly this
                               //  with p0.reserve(cfg.n_steps + 1) — pro habit.)
        for (std::size_t i = 0; i < n; ++i)
            centers_.emplace_back("NV_" + std::to_string(i), 3);
            // emplace_back constructs IN PLACE on the land — no temporary,
            // no copy, no move. The building is erected where it will live.
    }

    [[nodiscard]] std::size_t size() const { return centers_.size(); }

    // NO destructor. NO copy ctor. NO move ctor. NO assignment. NO delete.
    // Rule of Zero: std::vector handles every lifetime below us.
private:
    std::vector<Building> centers_;
};

void rule_of_zero() {
    header("§7  RULE OF ZERO — an ensemble with no memory code at all");
    {
        NVEnsemble ensemble(3);
        std::cout << "    ensemble of " << ensemble.size()
                  << " NV centers, alive and heap-backed.\n"
                  << "    NVEnsemble contains ZERO lines of memory management.\n";
    }   // ← one brace. Watch the whole city block come down, correctly, in order.
    std::cout << "    ...and the compiler wrote every demolition for us.\n";
}

// ────────────────────────────────────────────────────────────
// §8  FINAL REPORT — the city registry balances the books
// ────────────────────────────────────────────────────────────
void final_report() {
    header("§8  FINAL REPORT — does the registry balance?");
    std::cout << "  buildings ever commissioned : " << Building::total()    << "\n";
    std::cout << "  brick-by-brick copies       : " << Building::copies()   << "\n";
    std::cout << "  deed transfers (moves)      : " << Building::moves()    << "\n";
    std::cout << "  STILL STANDING              : " << Building::standing() << "\n\n";

    if (Building::standing() == 1) {
        std::cout << "  Exactly ONE building stands: the LEAKED_Reactor from §3,\n"
                  << "  lost on purpose. Our own counter caught it — and this is\n"
                  << "  precisely what professionals automate:\n\n"
                  << "     g++ -std=c++17 -g -fsanitize=address mini_03_memory_universe.cpp\n"
                  << "     ./a.out   → LeakSanitizer names the allocation site at exit.\n\n"
                  << "  Correct code is good. PROVABLY correct code is professional.\n";
    } else if (Building::standing() == 0) {
        std::cout << "  Registry balanced perfectly — no leaks anywhere.\n";
    } else {
        std::cout << "  ⚠ Unexpected count — investigate before trusting this build.\n";
    }
}

} // namespace QuantumGrav


int main() {
    using namespace QuantumGrav;

    std::cout << "╔══════════════════════════════════════════════════════╗\n";
    std::cout << "║   MINI-03: THE MEMORY UNIVERSE                       ║\n";
    std::cout << "║   your desk/land/huskelapp model — compiled          ║\n";
    std::cout << "╚══════════════════════════════════════════════════════╝\n";

    the_desk();          // §1  stack: automatic, scoped, LIFO
    the_land_raw();      // §2  heap: new/delete, note-on-desk vs building-on-land
    bug_gallery();       // §3  leak (live!), dangling, escaped local, double-free
    references_tour();   // §4  value vs const& vs &
    smart_deeds();       // §5  unique/shared/weak — ownership as structure
    move_benchmark();    // §6  std::move, measured
    rule_of_zero();      // §7  the pinnacle: no memory code at all
    final_report();      // §8  the books, balanced minus one deliberate crime

    std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"
              << "NEXT →  mini_04_matrix_ops.cpp  (spin-1 Sx, Sy, Sz by hand)\n"
              << "        Everything there lives on the DESK — and now you\n"
              << "        know exactly why that's the right call for 3×3.\n"
              << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
    return 0;
}